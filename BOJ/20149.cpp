#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

int CCW(pair<ld, ld> p1, pair<ld, ld> p2, pair<ld, ld> p3){
	ld temp=p1.first*p2.second+p2.first*p3.second+p3.first*p1.second-p1.second*p2.first-p2.second*p3.first-p3.second*p1.first;
	if(temp>0)
		return 1;
	else if(temp==0)
		return 0;
	else
		return -1;
}
int chk(pair<ld, ld> A, pair<ld, ld> B, pair<ld, ld> C, pair<ld, ld> D){
	int abc=CCW(A, B, C);
	int abd=CCW(A, B, D);
	int tmp1=abc*abd;
	int acd=CCW(C, D, A);
	int bcd=CCW(C, D, B);
	int tmp2=acd*bcd;
	if(tmp1==0 && tmp2==0){
		if(A>B)
			swap(A, B);
		if(C>D)
			swap(C, D);
		if(abc==0 && abd==0 && acd==0 && bcd==0 && B!=C && A<=D && C<=B)
			return 2;
		else if(A<=D && C<=B)
			return 1;
		else
			return 0;
	}
	else if(tmp1<=0 && tmp2<=0)
		return 1;
	else
		return 0;
}
void crossPoint(pair<ld, ld> A, pair<ld, ld> B, pair<ld, ld> C, pair<ld, ld> D){
	ld m1, m2, b1, b2;
	int chk1=0, chk2=0;
	if(A.first==B.first){
		chk1=1;
		b1=A.first;
	}
	if(C.first==D.first){
		chk2=1;
		b2=C.first;
	}
	if(!chk1){
		m1=(A.second-B.second)/(A.first-B.first);
		b1=A.second-m1*A.first;
	}
	if(!chk2){
		m2=(C.second-D.second)/(C.first-D.first);
		b2=C.second-m2*C.first;
	}
	if(chk1)
		printf("%.10Lf %.10Lf", b1, m2*b1+b2);
	else{
		if(chk2)
			printf("%.10Lf %.10Lf", b2, m1*b2+b1);
		else if(m1==m2){
			if(A.first==C.first && A.second==C.second)
				printf("%.10Lf %.10Lf", C.first, C.second);
			else if(A.first==D.first && A.second==D.second)
				printf("%.10Lf %.10Lf", D.first, D.second);
			else if(B.first==C.first && B.second==C.second)
				printf("%.10Lf %.10Lf", C.first, C.second);
			else if(B.first==D.first && B.second==D.second)
				printf("%.10Lf %.10Lf", D.first, D.second);
		}
		else
			printf("%.10Lf %.10Lf", (b2-b1)/(m1-m2), m1*(b2-b1)/(m1-m2)+b1);
	}
}
int main(){
	pair<ld, ld> l1[2];
	pair<ld, ld> l2[2];
	scanf("%Lf %Lf %Lf %Lf", &l1[0].first, &l1[0].second, &l1[1].first, &l1[1].second);
	scanf("%Lf %Lf %Lf %Lf", &l2[0].first, &l2[0].second, &l2[1].first, &l2[1].second);
	int tmp=chk(l1[0], l1[1], l2[0], l2[1]);
	if(tmp==1){
		printf("1\n");
		crossPoint(l1[0], l1[1], l2[0], l2[1]);
	}
	else
		printf("%d", tmp==0 ? 0:1);
	return 0;
}

#include <stdio.h>
#include <math.h>

int main(){
	long long int n, a, b, cnt1=0, d1[100], cnt2=0, d2[100], res=0;
	scanf("%lld %lld %lld", &n, &a, &b);
	for(int i=16;a!=0 && i>=0;i--){
		int x=pow(2, i);
		if(a-x>=0){
			d1[cnt1++]=x;
			a-=x;
		}
	}
	for(int i=16;b!=0 && i>=0;i--){
		int x=pow(2, i);
		if(b-x>=0){
			d2[cnt2++]=x;
			b-=x;
		}
	}
	cnt1--;
	cnt2--;
	while(cnt1!=-1){
		if(d1[cnt1]==1) res+=2;
		else res+=2*pow(d1[cnt1], 2);
		cnt1--;
	}
	while(cnt2!=-1){
		if(d2[cnt2]==1) res+=1;
		else res+=pow(d2[cnt2], 2);
		cnt2--;
	}
	printf("%lld", res);
}

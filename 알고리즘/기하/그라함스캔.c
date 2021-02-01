#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
typedef struct{
	ll x;
	ll y;
}Point;
Point p[100000], answer[100001];
int ccw(Point p1, Point p2, Point p3){
   ll tmp=p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.y*p2.x-p2.y*p3.x-p3.y*p1.x;
   if(tmp<0)
      return -1;
   else if(tmp>0)
      return 1;
   else
      return 0;
}

int compare(const void *a, const void *b){
	Point p1=*(Point*)a;
	Point p2=*(Point*)b;
	int tmp=ccw(p[0], p1, p2);
	if(tmp==0){
		if(p1.x==p2.x){
			if(p1.y<p2.y)
				return -1;
			else if(p1.y>p2.y)
				return 1;
			else
				return 0;
		}
		else{
			if(p1.x<p2.x)
				return -1;
			else if(p1.x>p2.x)
				return 1;
			else
				return 0;
		}
	}
	else{
		if(tmp>0)
			return -1;
		else
			return 1;
	}
}

int solution(int n){
	int top=0;
	for(int i=0;i<n;i++){
		while(top>1 && ccw(answer[top-1], answer[top], p[i])<=0)
			top--;
		answer[++top]=p[i];
	}
	return top;
}

int main(){
	int n, pivot=0;
	scanf("%d", &n);
	Point tmp;
	for(int i=0;i<n;i++){
		scanf("%lld %lld", &p[i].x, &p[i].y);
		if(p[i].x<p[pivot].x)
			pivot=i;
		else if(p[i].x==p[pivot].x && p[i].y<p[pivot].y)
			pivot=i;
	}
	tmp=p[0];
	p[0]=p[pivot];
	p[pivot]=tmp;
	qsort(p+1, n-1, sizeof(Point), compare);
	int count=solution(n);
	for(int i=1;i<=count;i++)
   	printf("%lld %lld\n", answer[i].x, answer[i].y);
}

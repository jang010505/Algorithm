#include <stdio.h>

typedef long long ll;

typedef struct{
	ll x;
	ll y;
}Point;

int compare(Point p1, Point p2, Point p3){
	ll dx1=p2.x-p1.x, dy1=p2.y-p1.y;
	ll dx2=p3.x-p1.x, dy2=p3.y-p1.y;
	if(dx1*dy2>dy1*dx2) return 1;
	if(dx1*dy2<dy1*dx2) return -1;
	if(dx1==0 && dx2==0) return 0;
	if(dx1*dx2<0 || dy1*dy2<0) return -1;
	if(dx1*dx1+dy1*dy1<dx2*dx2+dy2*dy2) return 1;
	return 0;
}

int solution(Point p[]){
	int tmp1=compare(p[0], p[1], p[2])*compare(p[0], p[1], p[3]);
	int tmp2=compare(p[2], p[3], p[0])*compare(p[2], p[3], p[1]);
	if(tmp1<=0 && tmp2<=0)
		return 1;
	else
		return 0;
}

int main(){
	Point p[4];
	for(int i=0;i<4;i++)
		scanf("%lld %lld", &p[i].x, &p[i].y);
	if(solution(p))
		printf("1");
	else
		printf("0");
}

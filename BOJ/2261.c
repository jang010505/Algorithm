#include <stdio.h>
#include <stdlib.h>
#define MIN(x, y) (x > y ? y:x)

struct Point{
	int x;
	int y;
};
struct Point p[500000], mid[500000];

int compare(const void* a, const void* b){
	struct Point p1=*(struct Point*)a;
	struct Point p2=*(struct Point*)b;
	if(p1.x>p2.x)
		return 1;
	else if(p1.x<p2.x)
		return -1;
	else
		return 0;
}
int compare2(const void* a, const void* b){
	struct Point p1=*(struct Point*)a;
	struct Point p2=*(struct Point*)b;
	if(p1.y>p2.y)
		return 1;
	else if(p1.y<p2.y)
		return -1;
	else
		return 0;
}

int min2(int a, int b){
    return (a<b)?a:b;
}

int min3(int a, int b, int c){
    a=(a<b)?a:b;
    return (a<c)?a:c;
}

int dist(int x1, int y1, int x2, int y2){
	return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

int closestPair(int l, int r){
	if(r-l==1)
		return dist(p[l].x, p[l].y, p[r].x, p[r].y);
	if(r-l==2){
		return min3(dist(p[l].x, p[l].y, p[l+1].x, p[l+1].y), dist(p[l].x, p[l].y, p[r].x, p[r].y), dist(p[l+1].x, p[l+1].y, p[r].x, p[r].y));
	}
	int line=(p[l].x+p[r].x)/2;
	int d=min2(closestPair(l, (l+r)/2), closestPair((l+r)/2+1, r));
	int count=0;
	for(int i=l;i<r;i++){
		int t=line-p[i].x;
		if(t*t<d)
			mid[count++]=p[i];
	}
	qsort(mid, count, sizeof(struct Point), compare2);
	for(int i=0;i<count-1;i++){
		for(int j=i+1;j<count && (mid[j].y-mid[i].y)*(mid[j].y-mid[i].y)<d;j++){
			d=min2(d, dist(mid[i].x, mid[i].y, mid[j].x, mid[j].y));
		}
	}
	return d;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	qsort(p, n, sizeof(struct Point), compare);
	printf("%d", closestPair(0, n-1));
	return 0;
}

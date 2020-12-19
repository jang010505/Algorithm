#include <stdio.h>
int n, p, e, min, u[30];
typedef struct ans{
	int a;
	int b;
}Res;
Res res[30];
int f(int x, int y, int minn, int maxn){
	if(x==0) {
		min=minn;
		if(minn<=e && e<=maxn) return 1;
		return 0;
	}
	if(y>=n) return 0;
	u[y]=1;
	if(f(x-1, y+1, minn+res[y].a, maxn+res[y].b))
		return 1;
	u[y]=0;
	if(f(x, y+1, minn, maxn))
		return 1;
	return 0;
}
int main(){
	scanf("%d %d %d", &n, &p, &e);
	for(int i=0;i<n;i++) scanf("%d %d", &res[i].a, &res[i].b);
	if(f(p, 0, 0, 0)==0){
		printf("-1");
		return 0;
	}
	e-=min;
	for(int i=0;i<n;i++) {
		int v;
		if(u[i]==0) printf("0 ");
		else{
			if(res[i].a+e<res[i].b) v=res[i].a+e;
			else v=res[i].b;
			printf("%d ", v);
			e=e-(v-res[i].a);
		}
	}
}

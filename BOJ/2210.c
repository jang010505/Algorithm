#include <stdio.h>
#define MAX(x, y) (x>y ? x:y)
int d[6][6], visit[1000000];
void dfs(int i, int j, int count, int taget){
	if(count==5){
		visit[taget]=1;
		return;
	}
	if(i>0) dfs(i-1, j, count+1, taget*10+d[i-1][j]);
	if(j>0) dfs(i, j-1, count+1, taget*10+d[i][j-1]);
	if(i<4) dfs(i+1, j, count+1, taget*10+d[i+1][j]);
	if(j<4) dfs(i, j+1, count+1, taget*10+d[i][j+1]);
	return;
}
int main(){
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			scanf("%d", &d[i][j]);
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			dfs(i, j, 0, d[i][j]);
	int cnt=0;
	for(int i=0;i<1000000;i++)
		if(visit[i])
			cnt++;
	printf("%d", cnt);
}

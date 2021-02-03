#include <cstdio>
#include <algorithm>

using namespace std;
int n, m, t, d, answer;
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
int map[700][700];
char info[26][26];

int chk(int x, int y){
	if((0<=x && x<n) || (0<=y && y<m))
		return 1;
	else
		return 0;
}

int get(int x, int y){
	if('A'<=info[x][y] && info[x][y]<='Z')
		return info[x][y]-'A';
	else
		return info[x][y]-'a'+26;
}

int main(){
	scanf("%d %d %d %d", &n, &m, &t, &d);
	for(int i=0;i<n;i++)
		scanf("%s", info[i]);
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(i==j)
				map[i][j]=0;
			else
				map[i][j]=1000000000;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int now=i*m+j;
			for(int k=0;k<4;k++){
				int x=i+dx[k];
				int y=j+dy[k];
				if(!chk(x, y))
					continue;
				int nxt=x*m+y;
				int diff=get(i, j)-get(x, y);
				if(abs(diff)>t)
					continue;
				if(diff>=0)
					map[now][nxt]=1;
				else
					map[now][nxt]=diff*diff;
			}
		}
	}
	for(int k=0;k<n*m;k++)
		for(int i=0;i<n*m;i++)
			for(int j=0;j<n*m;j++)
				map[i][j]=min(map[i][j], map[i][k]+map[k][j]);
	/*
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(map[i][j]!=1000000000)
				printf("%2lld ", map[i][j]);
			else
				printf(" X ");
		}
		printf("\n");
	}
	*/
	answer=0;
	for(int i=0;i<n*m;i++)
		if(map[0][i]+map[i][0]<=d)
			answer=max(answer, get(i/m, i%m));
	printf("%d", answer);
	return 0;
}

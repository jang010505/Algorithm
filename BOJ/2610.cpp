#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n, m, info[101][101], visit[101]={};
	vector <int> v;
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)
				info[i][j]=0;
			else
				info[i][j]=1000000000;
		}
	}
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		info[a][b]=1;
		info[b][a]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				info[i][j]=min(info[i][j], info[i][k]+info[k][j]);
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(info[i][j]!=1000000000)
				printf("%d ", info[i][j]);
			else
				printf("X ");
		}
		printf("\n");
	}
	*/
	for(int k=1;k<=n;k++){
		if(visit[k]==0){
			int MIN=1000000000, index=1, visit_info[101]={};
			for(int i=1;i<=n;i++){
				if(info[k][i]!=1000000000){
					visit_info[i]=1;
					visit[i]=1;
				}
			}
			for(int i=1;i<=n;i++){
				if(visit_info[i]==0)
					continue;
				int MAX=0;
				for(int j=1;j<=n;j++)
					if(info[i][j]!=1000000000)
						MAX=max(MAX, info[i][j]);
				if(MIN>MAX){
					MIN=MAX;
					index=i;
				}
			}
			v.push_back(index);
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for(int i=0;i<v.size();i++)
		printf("%d\n", v[i]);
	return 0;
}

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int map[9][9];

int rowchk(int col){
	int chk[10]={0, };
	for(int i=0;i<9;i++){
		if(map[col][i]!=0)
			chk[map[col][i]]++;
		if(chk[map[col][i]]>=2)
			return 0;
	}
	return 1;
}
int colchk(int row){
	int chk[10]={0, };
	for(int i=0;i<9;i++){
		if(map[i][row]!=0)
			chk[map[i][row]]++;
		if(chk[map[i][row]]>=2)
			return 0;
	}
	return 1;
}
int squchk(int col, int row){
	int chk[10]={0, };
	for(int i=col/3*3;i<(col/3)*3+3;i++){
		for(int j=row/3*3;j<(row/3)*3+3;j++){
			if(map[i][j]!=0)
				chk[map[i][j]]++;
			if(chk[map[i][j]]>=2)
				return 0;
		}
	}
	return 1;
}
void solution(void){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(map[i][j]==0){
				for(int k=1;k<=9;k++){
					map[i][j]=k;
					if(rowchk(i) && colchk(j) && squchk(i, j))
						solution();
					map[i][j]=0;
				}
				return;
			}
			if(i==8 && j==8){
				for(int i=0;i<9;i++)
					for(int j=0;j<9;j++)
						if(map[i][j]==0)
							return;
				for(int i=0;i<9;i++){
					for(int j=0;j<9;j++){
						printf("%d ", map[i][j]);
					}
					printf("\n");
				}
				exit(0);
			}
		}
	}
}
int main(){
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			scanf("%d", &map[i][j]);
	solution();
	return 0;
}

#include <stdio.h>

int A[100][100], B[100][100], result[100][100];
void multiplyMatrix(int a, int b, int c){
	for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
			for(int k=0;k<c;k++)
				result[i][k]+=A[i][j]*B[j][k];
	return;
}
int main(){
	int n, m, k;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d", &A[i][j]);
	scanf("%d %d", &m, &k);
	for(int i=0;i<m;i++)
		for(int j=0;j<k;j++)
			scanf("%d", &B[i][j]);
	multiplyMatrix(n, m, k);
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}

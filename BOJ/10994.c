#include <stdio.h>
char d[1000][1000];

int main(){
    int n, i, j, k;
    scanf("%d", &n);
    if(n==1){
    	printf("*");
    	return 0;
	}
	for(i=0;i<n-1;i++){
		for(j=i*2;j<4*(n-1)+1-i*2;j++){
			for(k=i*2;k<4*(n-1)+1-i*2;k++){
				if(j==i*2 || j==4*(n-1)-i*2) d[j][k]='*';
				else{
					if(k==i*2 || k==4*(n-1)-i*2) d[j][k]='*';
					else d[j][k]=' ';
				}
			}
		}
	}
	d[4*(n-1)/2][4*(n-1)/2]='*';
	for(i=0;i<4*(n-1)+1;i++){
		for(j=0;j<4*(n-1)+1;j++){
			printf("%c", d[i][j]);
		}
		printf("\n");
	}
}

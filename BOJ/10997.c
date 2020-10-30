#include <stdio.h>
char d[1000][1000];

int main(){
    int n, i, j;
    scanf("%d", &n);
    if(n==1){
    	printf("*");
    	return 0;
	}
	for(i=0;i<1+n*4;i++){
		for(j=0;j<1+n*4;j++) d[i][j]=' ';
	}
	int c=(1+(n-1)*4)/2, r=(1+(n-1)*4)/2+2, l=3;
	for(i=0;i<l;i++) d[r-i][c]='*';
	r-=2;
	for(i=0;i<l;i++) d[r][c+i]='*';
	c+=2;
	l+=2;
	for(i=0;i<n-1;i++){
		for(j=0;j<l;j++) d[r+j][c]='*';
		r+=l-1;
		for(j=0;j<l;j++) d[r][c-j]='*';
		c-=l-1;
		l+=2;
		for(j=0;j<l;j++) d[r-j][c]='*';
		r-=l-1;
		for(j=0;j<l;j++) d[r][c+j]='*';
		c+=l-1;
		l+=2;
	}
	for(i=0;i<n*4-1;i++){
		if(i==1) printf("*");
		else {
			for(j=0;j<n*4-3;j++){
				printf("%c", d[i][j]);
			}
		}
		if(i!=n*4-2)printf("\n");
	}
}

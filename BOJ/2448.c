#include <stdio.h>
char d[4000][7000];

int f(int l, int a, int b){
    if(l==3){
        d[a][b]='*';
   	 	d[a+1][b+1]='*';
    	d[a+1][b-1]='*';
    	for(int i=0;i<5;i++) d[a+2][b-2+i]='*';
        return 0;
    }
    f(l/2, a, b);
    f(l/2, a+l/2, b-l/2);
    f(l/2, a+l/2, b+l/2);
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++) d[i][j]=' ';
    }
    f(n,0,n-1); 
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++) printf("%c", d[i][j]);
        printf("\n");
    }
    return 0;
}

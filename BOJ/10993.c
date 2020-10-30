#include <stdio.h>
#include <string.h>
char d[2000][4000];
int k(int a, int b){
    if (b==0) return 1;
    return k(a, b-1)*a;
}
int g(int l, int a, int b, int x, int y){
    if(l%2){
        for(int i=0;i<x;i++){
            if(i==0){
                for(int j=0;j<y;j++) d[a][b+j]='*';
            }
            else if(i==x-1) d[a-i][b+x-1]='*';
            else{
                d[a-i][b+i]='*';
                d[a-i][b+y-i-1]='*';
            }
        }
    }
    else{
        for(int i=0;i<x;i++){
            if(i==0){
                for(int j=0;j<y;j++) d[a][b+j]='*';
            }
            else if(i==x-1) d[a+i][b+x-1]='*';
            else{
                d[a+i][b+i]='*';
                d[a+i][b+y-i-1]='*';
            }
        }
    }
    return 0;
}
int f(int l, int i, int j){
    int x=k(2, l)-1;
    int y=k(2, l+1)-3;   
    g(l, i, j, x, y);
    if(l==1) return 0;
    if(l%2) f(l-1, i-x/2, j+x/2+1);
    else f(l-1, i+x/2, j+x/2+1);
}

int main(){
    int n, x, y;
    scanf("%d", &n);
    x=k(2, n)-1;
    y=k(2, n+1)-3;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++) d[i][j]=' ';
    }
    if(n%2) f(n, x-1, 0);
    else f(n, 0, 0);
    for(int i=0;i<x;i++){
        if(n%2){
            for(int j=0;j<x+i;j++) printf("%c", d[i][j]);
        }
        else{
            for(int j=0;j<y-i;j++) printf("%c", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int n, cnt=0, a[15];
int g(int x){
    for(int i=0;i<x-1;i++){
        if(a[i]==a[x-1] || abs(a[i]-a[x-1])+1==x-i) return 0;
    }
    return 1;
}
int f(int x){
    if(x==n){
        cnt++;
        return 0;
    }
    for(int i=0;i<n;i++){
        a[x]=i;
        if(g(x+1)) f(x+1);
    }
}
int main(){
	scanf("%d", &n);
    f(0);
    printf("%d", cnt);
}

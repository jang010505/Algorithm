#include <stdio.h>

int f(int x, int y){
    if(y==0) return x;
    return f(y, x%y);
}
int main(){
    int a, b, gcd;
    scanf("%d %d", &a, &b);
    gcd=f(a, b);
    printf("%d\n%d", gcd, a/gcd*b);
}

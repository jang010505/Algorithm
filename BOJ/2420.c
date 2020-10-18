#include <stdio.h>

int main(){
    long long int a, b, res;
    scanf("%lld %lld", &a, &b);
    res=a-b;
    if(res<0) res*=-1;
    printf("%lld", res);
}

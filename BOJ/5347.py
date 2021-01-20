#include <stdio.h>
typedef long long ll;
ll gcd(ll a, ll b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        ll a, b;
        scanf("%lld %lld", &a, &b);
        printf("%d\n", lcm(a, b));
    }
}

#include <stdio.h>

int main(){
    int a, i, res=0;
    for(i=0;i<5;i++){
        scanf("%d", &a);
        res+=a*a;
    }
    printf("%d", res%10);
}

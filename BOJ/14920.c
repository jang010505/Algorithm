#include <stdio.h>
void f(int a, int cnt){
    if(a==1){
        printf("%d", cnt);
        return;
    }
    if(a%2==0) f(a/2, cnt+1);
    else f(3*a+1, cnt+1);
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    f(n, 0);
	return 0;
}

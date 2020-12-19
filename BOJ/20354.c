#include <stdio.h>
#include <string.h>

int d[2000000];
int main(){
    int n, q, a;
    scanf("%d %d", &n, &q);
    for(int i=0;i<q;i++){
        int chk=1;
        scanf("%d", &a);
        int A=a, x[30], k=0;
        while(a!=0){
            x[k]=a%2;
            a/=2;
            k++;
        }
        a=0;
        for(int j=k-1;j>=0;j--){
            if(x[j]==1){
                a=a*2+1;
            }
            else a=a*2;
            if(chk==1 && d[a]==1){
                printf("%d\n", a);
                chk=0;
            }
        }
        d[A]=1;
        if(chk==1){
            printf("0\n");
        }
    }
}

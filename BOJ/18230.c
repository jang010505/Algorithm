#include <stdio.h>
#include <stdlib.h>
int f(const void* a, const void* b){
	if(*(int*)a>*(int*)b) return -1;
	else if(*(int*)a<*(int*)b) return 1;
	else return 0;
}
int main(){
	int n, a, b, i, j, k=0, x[2005], y[2005], res=0;
	scanf("%d %d %d", &n, &a, &b);
	for(i=0;i<a;i++) scanf("%d", &x[i]);
	for(i=0;i<b;i++) scanf("%d", &y[i]);
	qsort(x, a, sizeof(int), f);
	qsort(y, b, sizeof(int), f);
	i=0;
	j=0;
	if(n%2){
		res+=x[i];
		i++;
		k++;
	}
	while(k!=n){
		if(x[i]+x[i+1]>y[j] && i+1<a){
			res+=x[i]+x[i+1];
			i+=2;
			k+=2;
		}
		else if(x[i]+x[i+1]<=y[j] && j<b){
			res+=y[j];
			j++;
			k+=2;
		}
		else if(i+1>=a){
            res+=y[j];
            j++;
            k+=2;
        }
        else if(j>=b){
            res+=x[i]+x[i+1];
            i+=2;
            k+=2;
        }
	}
	printf("%d", res);
}

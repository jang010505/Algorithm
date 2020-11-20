#include <stdio.h>
#include <math.h>
char x[1000000];
int main(){
	int n, a, d[100001]={}, k=1, z=1, l=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a);
		if(d[a]==2){
			z=0;
			break;
		}
		else if(d[a]==1){
			for(;k>a;){
				if(d[--k]==1) x[l++]='-';
				if(d[k]==1) d[k]=2;
			}
		}
		else{
			for(;k<=a;){
				if(d[k]==0) d[k]=1;
				if(d[k]==1) x[l++]='+';
				k++;
			}
			d[--k]=2;
			x[l++]='-';
		}
	}
	if(z) for(int i=0;i<l;i++) printf("%c\n", x[i]);
	else printf("NO");
}

#include <stdio.h>
#include <string.h>

int main(){
	int n, m, k=0, res[100], d[100], x[10]={9, 4, 8, 7, 2, 1, 6, 5, 0, 3};
	scanf("%d %d", &n, &m);
	for(int i=n;i<=m;i++){
		res[k]=i;
		if(i<10) d[k++]=x[i%10]*10;
		else d[k++]=x[i/10]*10+x[i%10];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<k-i-1;j++){
			if(d[j]>d[j+1])
			{
				int temp=d[j+1];
				d[j+1]=d[j];
				d[j]=temp;
				temp=res[j+1];
				res[j+1]=res[j];
				res[j]=temp;
			}
		}
	}
	for(int i=0;i<k;i++){
		if(i%10==9) printf("%d\n", res[i]);
		else printf("%d ", res[i]);
	}
}

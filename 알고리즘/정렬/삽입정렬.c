#include <stdio.h>

int main(){
	int n, d[1000], temp;
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	for(int i=0;i<n-1;i++){
		int j=i;
		while(d[j]>d[j+1]){
			temp=d[j];
			d[j]=d[j+1];
			d[j+1]=temp;
			j--;
		}
	}
	for(int i=0;i<n;i++) printf("%d ", d[i]);
}

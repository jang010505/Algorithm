#include <stdio.h>

int main(){
	int n, d[1000], temp;
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	for(int i=0;i<n;i++){
		for(int j=i;j<n-1;j++){
			if(d[j]>d[j+1]){
				temp=d[j];
				d[j]=d[j+1];
				d[j+1]=temp;
			}
		}
	}
	for(int i=0;i<n;i++) printf("%d ", d[i]);
}

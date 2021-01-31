#include <stdio.h>

int main(){
	int n, d[1000];
	scanf("%d", &n); 
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	for(int i=0;i<n;i++){
		int min=2100000000, temp, index;
		for(int j=i;j<n;j++){
			if(d[j]<min){
				min=d[j];
				index=j;
			}
		}
		temp=d[i];
		d[i]=d[index];
		d[index]=temp;
	}
	for(int i=0;i<n;i++) printf("%d ", d[i]);
}

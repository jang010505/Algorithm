#include <stdio.h>

void bubbleSort(int d[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(d[j]>d[j+1]){
				int temp=d[j];
				d[j]=d[j+1];
				d[j+1]=temp;
			}
		}
	}
	return;
}
void print(int d[], int n){
	for(int i=0;i<n;i++)
		printf("%d ", d[i]);
}
int main(){
	int n, d[100001];
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	bubbleSort(d, n);
	print(d, n);
	return 0;
}

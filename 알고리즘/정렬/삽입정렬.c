#include <stdio.h>

void insertionSort(int d[], int n){
	for(int i=0;i<n-1;i++){
		int j=i;
		while(d[j]>d[j+1]){
			int temp=d[j];
			d[j]=d[j+1];
			d[j+1]=temp;
			j--;
		}
	}
	return;
}
void print(int d[], int n){
	for(int i=0;i<n;i++)
		printf("%d ", d[i]);
	return;
}
int main(){
	int n, d[100001];
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	insertionSort(d, n);
	print(d, n);
	return 0;
}

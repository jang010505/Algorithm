#include <stdio.h>

void selectionSort(int d[], int n){
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
	selectionSort(d, n);
	print(d, n);
	return 0;
}

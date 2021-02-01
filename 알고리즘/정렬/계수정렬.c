#include <stdio.h>

void countingSort(int d[], int count[], int n){
	for(int i=0;i<n;i++)
		count[d[i]]++;
	return;
}
void print(int count[], int max){
	for(int i=1;i<=max;i++)
		for(int j=0;j<count[i];j++)
			printf("%d ", i);
	return;
}
int main(){
	int n, m, d[100001], count[100001]={}, max=0;
	scanf("%d", &n); 
	for(int i=0;i<n;i++){
		scanf("%d", &d[i]);
		if(max<d[i])
			max=d[i];
	}
	countingSort(d, count, n);
	print(count, max);
	return 0;
}

#include <stdio.h>

int partition(int d[], int left, int right){
	int pivot, temp;
	int low, high;
	low=left;
	high=right+1;
	pivot=d[left];
	do{
		do
			low++;
		while(low<=right && d[low]<pivot);
		do
			high--;
		while(high>=left && d[high]>pivot);
		if(low<high){
			temp=d[high];
			d[high]=d[low];
			d[low]=temp;
		}
	}
	while(low<high);
	temp=d[high];
	d[high]=d[left];
	d[left]=temp;
	return high;
}
void quickSort(int d[], int left, int right){
	if(left<right){
		int q=partition(d, left, right);
		quickSort(d, left, q-1);
		quickSort(d, q+1, right);
	}
	return;
}
void print(int d[], int n){
	for(int i=0;i<n;i++)
		printf("%d ", d[i]);
	return;
}
int main(){
	int d[100001], n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	quickSort(d, 0, n-1);
	print(d, n);
	return 0;
}

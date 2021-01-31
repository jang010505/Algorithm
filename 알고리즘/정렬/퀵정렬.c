#include <stdio.h>

int d[1000001], n;

int partition(int left, int right){
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
void quick_sort(int left, int right){
	if(left<right){
		int q=partition(left, right);
		quick_sort(left, q - 1);
		quick_sort(q + 1, right);
	}
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	quick_sort(0, n-1);
	for(int i=0;i<n;i++)
		printf("%d\n", d[i]);
}

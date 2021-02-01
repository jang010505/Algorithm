#include <stdio.h>

void mergeSort(int d[], int result[], int left, int mid, int right){
	int i=left, j=mid+1, k=left;
	while(i<=mid && j<=right){
		if(d[i]<=d[j]){
			result[k]=d[i];
			i++;
		}
		else{
			result[k]=d[j];
			j++;
		}
		k++;
	}
	if(i>mid){
		while(j<=right){
			result[k]=d[j];
			k++;
			j++;
		}
	}
	else{
		while(i<=mid){
			result[k]=d[i];
			k++;
			i++;
		}
	}
	for(int t=left;t<=right;t++)
		d[t]=result[t];
	return;
}
void merge(int d[], int result[], int left, int right){
	if(left<right){
		int mid=(left+right)/2;
		merge(d, result, left, mid);
		merge(d, result, mid+1, right);
		mergeSort(d, result, left, mid, right);
	}
	return;
}
void print(int result[], int n){
	for(int i=0;i<n;i++)
		printf("%d ", result[i]);
	return;
}
int main(){
	int n, d[100001], result[100001];
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	merge(d, result, 0, n-1);
	print(result, n);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
typedef struct Member{
	int year;
	char name[101];
}member; 
void merge(member *list, int left, int mid, int right){
	int i=left, j=mid+1, k=left;
	member *temp=(member*)malloc(sizeof(member)*(right+1));
	while(i<=mid && j<=right){
		if(list[i].year<=list[j].year){
			temp[k]=list[i];
			i++;
		}
		else{
			temp[k]=list[j];
			j++;
		}
		k++;
	}
	if(i>mid){
		while(j<=right){
			temp[k]=list[j];
			k++;
			j++;
		}
	}
	else{
		while(i<=mid){
			temp[k]=list[i];
			k++;
			i++;
		}
	}
	for(int i=left;i<=right;i++){
		list[i]=temp[i];
	}
	free(temp);
	return;
}
void mergeSort(member *list, int left, int right){
	if(left<right){
		int mid=(left+right)/2;
		mergeSort(list, left, mid);
		mergeSort(list, mid+1, right);
		merge(list, left, mid, right);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	member *list=(member*)malloc(sizeof(member)*n);
	for(int i=0;i<n;i++)
		scanf("%d %s", &list[i].year, list[i].name);
	mergeSort(list, 0, n-1);
	for(int i=0;i<n;i++)
		printf("%d %s\n", list[i].year, list[i].name);
	free(list);
	return 0;
}

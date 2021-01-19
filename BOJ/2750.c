#include <stdio.h>

int d[1000001], n;

inc_insertion_sort(int first, int last, int gap){
	int i, j, key;
	for(i=first+gap;i<=last;i=i+gap){
		key=d[i];
		for(j=i-gap;j>=first && key<d[j];j=j-gap)
			d[j+gap]=d[j];
		d[j+gap]=key;
	}
}
void shell_sort(int n){
	int i, gap;
	for(gap=n/2;gap>0;gap=gap/2){
		if((gap%2)==0)
			gap++;
		for(i=0;i<gap;i++)
			inc_insertion_sort(i, n-1, gap);
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	shell_sort(n);
	for(int i=0;i<n;i++)
		printf("%d\n", d[i]);
}

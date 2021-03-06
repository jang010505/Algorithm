#include <stdio.h>

void heapSort(int d[], int n){
	for(int i=1;i<n;i++){
		int c=i;
		do{
			int r=(c-1)/2;
			if(d[r]<d[c]){
				int temp=d[r];
				d[r]=d[c];
				d[c]=temp;
			}
			c=r;
		}while(c!=0);
	}
	for(int i=n-1;i>=0;i--){
		int temp=d[0], c, r=0;
		d[0]=d[i];
		d[i]=temp;
		do{
			c=2*r+1;
			if(d[c]<d[c+1] && c<i-1) c++;
			if(d[r]<d[c] && c<i){
				int temp=d[r];
				d[r]=d[c];
				d[c]=temp;
			}
			r=c;
		}while(c<i);
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
	heapSort(d, n);
	print(d, n);
	return 0;
}

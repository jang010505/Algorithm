#include <stdio.h>
int n, d[1000], res[1000];
void g(int a[], int m, int mid, int N){
	int i=m, j=mid+1, k=m;
	while(i<=mid && j<=N){
		if(a[i]<=a[j]){
			res[k]=a[i];
			i++;
		}
		else{
			res[k]=a[j];
			j++;
		}
		k++;
	}
	if(i>mid){
		while(j<=N){
			res[k]=a[j];
			k++;
			j++;
		}
	}
	else{
		while(i<=mid){
			res[k]=a[i];
			k++;
			i++;
		}
	}
	for(int t=m;t<=N;t++) a[t]=res[t];
}
void f(int a[], int N, int m){
	if(N<m){
		int mid=(N+m)/2;
		f(a, N, mid);
		f(a, mid+1, m);
		g(a, N, mid, m);
	}
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	f(d, 0, n-1);
	for(int i=0;i<n;i++) printf("%d ", d[i]);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct user{
	int year;
	char name[101];
}result;

void g(result *d, int m, int mid, int N){
	int i=m, j=mid+1, k=m;
	result *t=(result*)malloc(sizeof(result)*(N+1));
	while(i<=mid && j<=N){
		if(d[i].year<=d[j].year){
			t[k]=d[i];
			i++;
		}
		else{
			t[k]=d[j];
			j++;
		}
		k++;
	}
	if(i>mid){
		while(j<=N){
			t[k]=d[j];
			k++;
			j++;
		}
	}
	else{
		while(i<=mid){
			t[k]=d[i];
			k++;
			i++;
		}
	}
	for(int i=m;i<=N;i++){
		d[i]=t[i];
	}
	free(t);
}
void f(result *d, int N, int m){
	if(N<m){
		int mid=(N+m)/2;
		f(d, N, mid);
		f(d, mid+1, m);
		g(d, N, mid, m);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	result *d=(result*)malloc(sizeof(result)*n);
	for(int i=0;i<n;i++) scanf("%d %s", &d[i].year, d[i].name);
	f(d, 0, n-1);
	for(int i=0;i<n;i++) printf("%d %s\n", d[i].year, d[i].name);
	free(d);
}

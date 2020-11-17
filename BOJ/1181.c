#include <stdio.h>
#include <string.h>
int n, d[100]={};
char s[20000][100], res[20000][100];
void g(char a[][100], int m, int mid, int N){
	int i=m, j=mid+1, k=m;
	while(i<=mid && j<=N){
		if(strlen(a[i]) <= strlen(a[j])){
			strcpy(res[k], a[i]);
			i++;
		}
		else{
			strcpy(res[k], a[j]);
			j++;
		}
		k++;
	}
	if(i>mid){
		while(j<=N){
			strcpy(res[k], a[j]);
			k++;
			j++;
		}
	}
	else{
		while(i<=mid){
			strcpy(res[k], a[i]);
			k++;
			i++;
		}
	}
	for(int t=m;t<=N;t++) strcpy(a[t], res[t]);
}
void gg(char a[][100], int m, int mid, int N){
	int i=m, j=mid+1, k=m;
	while(i<=mid && j<=N){
		if(strcmp(a[i], a[j])<0){
			strcpy(res[k], a[i]);
			i++;
		}
		else{
			strcpy(res[k], a[j]);
			j++;
		}
		k++;
	}
	if(i>mid){
		while(j<=N){
			strcpy(res[k], a[j]);
			k++;
			j++;
		}
	}
	else{
		while(i<=mid){
			strcpy(res[k], a[i]);
			k++;
			i++;
		}
	}
	for(int t=m;t<=N;t++) strcpy(a[t], res[t]);
}
void f(char a[][100], int N, int m){
	if(N<m){
		int mid=(N+m)/2;
		f(a, N, mid);
		f(a, mid+1, m);
		g(a, N, mid, m);
	}
}
void ff(char a[][100], int N, int m){
	if(N<m){
		int mid=(N+m)/2;
		ff(a, N, mid);
		ff(a, mid+1, m);
		gg(a, N, mid, m);
	}
	return;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%s", s[i]);
		d[strlen(s[i])]++;
	}
	f(s, 0, n-1);
	int start=0, end=-1;
	for(int i=0;i<=50;i++){
		end+=d[i];
		ff(s, start, end);
		start+=d[i];
	}
	for(int i=0;i<n;i++){
		while(strcmp(s[i], s[i+1])==0) i++;
		printf("%s\n", s[i]);
	}
}

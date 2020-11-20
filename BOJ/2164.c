#include <stdio.h>
int n, d[2000005]={}, k, f=0, b;
int deque_fpop(){
	return d[f++];
}
void deque_bpush(){
	d[b++]=d[f++];
	return;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		d[i]=i+1;
	}
	b=n;
	for(int i=0;f!=b;i++){
		if(i%2==0){
			k=deque_fpop();
			if(f==b) printf("%d", k);
		}
		else deque_bpush();
	}
}

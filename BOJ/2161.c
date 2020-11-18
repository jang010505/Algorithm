#include <stdio.h>
int n, d[10000]={}, k;
int deque_fpop(){
	int res=d[0];
	for(int i=1;i<n;i++){
		d[i-1]=d[i];
	}
	n--;
	return res;
}
void deque_bpush(){
	int res=d[0];
	for(int i=1;i<n;i++){
		d[i-1]=d[i];
	}
	d[n-1]=res;
	return;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		d[i]=i+1;
	}
	for(int i=0;n!=0;i++){
		if(i%2==0){
			k=deque_fpop();
			printf("%d ", k);
		}
		else{
			deque_bpush();
		}
	}
}

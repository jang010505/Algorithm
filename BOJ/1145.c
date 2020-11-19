#include <stdio.h>
int d[5], min=100000000, chk[5]={};
int lcd(int a, int b, int A, int B){
	if(A==B) return A;
	else if(A>B) return lcd(a, b, A, B+b);
	else return lcd(a, b, A+a, B);
}
int f(int i, int res){
	if(i==3){
		if(min>res) min=res;
		return 0;
	}
	for(int j=0;j<5;j++){
		if(!chk[j]){
			chk[j]=1;
			f(i+1, lcd(res, d[j], res, d[j]));
			chk[j]=0;
		}
	}
	return 0;
}
int main(){
	for(int i=0;i<5;i++) scanf("%d", &d[i]);
	f(0, 1);
	printf("%d", min);
}

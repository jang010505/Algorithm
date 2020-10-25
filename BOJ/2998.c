#include <stdio.h>
#include <string.h>
char a[105];
int f(int l){
	if(l>1){
		int res=0;
		f(l-3);
		if(a[l]-48) res+=1;
		if(a[l-1]-48) res+=2;
		if(a[l-2]-48) res+=4;
		printf("%d", res);
	}
	else if(l==1){
		int res=0;
		if(a[l]-48) res+=1;
		if(a[l-1]-48) res+=2;
		printf("%d", res);
	}
	else if(l==0){
		int res=0;
		if(a[l]-48) res+=1;
		printf("%d", res);
	}
	return 0;
}
int main(){
	int i, res=0;
	scanf("%s", a);
	f(strlen(a)-1);
}

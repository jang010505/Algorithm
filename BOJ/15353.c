#include <stdio.h>
#include <string.h>

int main(){
	char a[10005], b[10005], res[10005];
	scanf("%s %s", a, b);
	int x=strlen(a)-strlen(b), i;
	if(x<0){
		for(i=strlen(a)-1;i>=0;i--) a[i+(x*-1)+1]=a[i];
		for(i=(x*-1);i>=0;i--) a[i]='0';
		for(i=strlen(b)-1;i>=0;i--) b[i+1]=b[i];
		b[0]='0';
	}
	else if(x>0){
		for(i=strlen(b)-1;i>=0;i--) b[i+x+1]=b[i];
		for(i=x;i>=0;i--) b[i]='0';
		for(i=strlen(a)-1;i>=0;i--) a[i+1]=a[i];
		a[0]='0';
	}
	else{
		for(i=strlen(a)-1;i>=0;i--) a[i+1]=a[i];
		a[0]='0';
		for(i=strlen(b)-1;i>=0;i--) b[i+1]=b[i];
		b[0]='0';
	}
	for(i=0;i<strlen(a);i++) res[i]=0;
	for(i=strlen(a)-1;i>0;i--){
		if(a[i]+b[i]+res[i]-96>=10){
			res[i-1]+=1;
			res[i]=a[i]+b[i]+res[i]-106;
		}
		else res[i]=a[i]+b[i]+res[i]-96;
	}
	for(i=0;i<strlen(a);i++){
		if(res[0]==0 && i==0) continue;
		printf("%d", res[i]);
	}
}

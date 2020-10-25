#include <stdio.h>
#include <string.h>

int main(){
	int n=0, i;
	char a[100];
	scanf("%s", a);
	for(i=0;a[i]!='\0';i++){
		if(a[i]>=97) n+=a[i]-96;
		else if(a[i]>=65) n+=a[i]-38;
	}
	for(i=2;i*i<=n;i++){
		if(n%i==0){
			printf("It is not a prime word.");
			return 0;
		}
	}
	printf("It is a prime word.");
	return 0;
}

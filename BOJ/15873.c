#include <stdio.h>
int main(){
	char x[5];
	scanf("%s", x);
	if(x[2]=='\0') printf("%d", x[0]+x[1]-96);
	if(x[3]=='\0' && x[1]=='0') printf("%d", 10+x[2]-48);
	if(x[3]=='\0' && x[2]=='0') printf("%d", 10+x[0]-48);
	if(x[4]=='\0' && x[3]!='\0') printf("20");
}

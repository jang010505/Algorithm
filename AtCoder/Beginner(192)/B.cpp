#include <cstdio>
#include <cstring>
 
using namespace std;
 
int main(){
	char s[2000];
	int chk=1;
	scanf("%s", s);
	for(int i=0;i<strlen(s);i+=2){
		if(!(97<=s[i] && s[i]<=122)){
			chk=0;
			break;
		}
	}
	for(int i=1;i<strlen(s);i+=2){
		if(!(65<=s[i] && s[i]<=90)){
			chk=0;
			break;
		}
	}
	if(chk)
		printf("Yes");
	else
		printf("No");
}

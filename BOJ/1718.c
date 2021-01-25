#include <stdio.h>

int main(){
	int now=0;
	char str1[100001], str2[100001];
	scanf("%[^\n]", str1);
	scanf("%s[^\n]", str2);
	for(int i=0;str1[i]!=NULL;i++){
		if(str2[now]==NULL)
			now=0;
		if(97<=str1[i] && str1[i]<=122){
			str1[i]-=str2[now]-96;
			if(str1[i]<97)
				str1[i]+=26;
		}
		now++;
	}
	printf("%s", str1);
}

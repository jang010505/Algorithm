#include <stdio.h>
#include <string.h>

void getpi(char str[], char find[], int pattern[]){
	int str_len=strlen(str);
	int find_len=strlen(find);
	for(int i=1 ,j=0;i<find_len;i++){
      while(j>0 && find[i]!=find[j])
			j=pattern[j-1];
      if(find[i]==find[j]){
         pattern[i]=++j;
      }
   }
   return;
}

int kmp(char str[], char find[], int pattern[], int answer[]){
	int str_len=strlen(str);
	int find_len=strlen(find);
	int count=0;
	for(int i=0, j=0;i<str_len;i++){
      while(j>0 && str[i]!=find[j])
			j=pattern[j-1];
      if(str[i]==find[j]){
         if(j==find_len-1){
            answer[count++]=i-find_len+2;
            j=pattern[j];
         }
         else
				j++;
      }
   }
   return count;
}
int main(){
	int count, pattern[100001], answer[100001];
	char str[100001], find[100001];
	gets(str);
	fflush(stdin);
	gets(find);
	getpi(str, find, pattern);
	count=kmp(str, find, pattern, answer);
	printf("%d\n", count);
	for(int i=0;i<count;i++)
		printf("%d ", answer[i]);
}

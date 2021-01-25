#include <stdio.h>
#include <string.h>

int count=0, pattern[1000001], answer[1000001];
char str[1000001], find[1000001];

int main(){
	gets(str);
	fflush(stdin);
	gets(find);
	int str_len=strlen(str);
	int find_len=strlen(find);
	for(int i=1 ,j=0;i<find_len;i++){
        while(j>0 && find[i]!=find[j])
			j=pattern[j-1];
        if(find[i]==find[j]){
            pattern[i]=++j;
        }
    }
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
	printf("%d\n", count);
	for(int i=0;i<count;i++)
		printf("%d ", answer[i]);
}

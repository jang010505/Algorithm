#include <stdio.h>
#include <string.h>

int pattern[1000001], answer=0;
char str[1000001];

int main(){
	gets(str);
	int str_len=strlen(str);
	for(int i=0;i<str_len;i++){
		int j=0;
        for(int k=i+1;k<str_len;k++){
            while(j>0 && str[k]!=str[i+j])
				j=pattern[j-1];
            if(str[k]==str[i+j]){
                j++;
                if(answer<j) 
					answer=j;
            }
            pattern[k-i]=j;
        }
    }
    printf("%d", answer);
}

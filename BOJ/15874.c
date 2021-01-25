#include <stdio.h>

int main(){
	int k, s;
	char str[100001];
	scanf("%d %d\n", &k, &s);
	scanf("%[^\n]", str);
	k%=26;
	for(int i=0;i<s;i++){
		int temp=str[i];
		if(65<=temp && temp<=90){
			temp+=k;
			if(temp>90){
				temp-=26;
			}
		}
		else if(97<=temp && temp<=122){
			temp+=k;
			if(temp>122){
				temp-=26;
			}
		}
		str[i]=temp;
	}
	printf("%s", str);
}

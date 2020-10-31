#include <stdio.h>

int main(){
	int a, b, c, res=0, i=0, cnt=0;
	scanf("%d %d %d", &a, &b, &c);
	while(res<c){
		res+=a;
		i++;
		cnt++;
		if(i==7){
			i=0;
			res+=b;
		}
	}
	printf("%d", cnt);
}

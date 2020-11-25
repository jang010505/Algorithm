#include <stdio.h>

int main(){
	int n, a, b, cnt1=1, cnt2=1;
	scanf("%d %d %d", &n, &a, &b);
	while(1){
		if(((a+1==b && b%2==0) || (b+1==a && a%2==0)) && cnt1==cnt2){
			printf("%d", cnt1);
			return 0;
		}
		if(cnt1==cnt2){
			if(a<b){
				if(b%2) b=(b+1)/2;
				else b/=2;
				cnt2++;
			}
			else{
				if(a%2) a=(a+1)/2;
				else a/=2;
				cnt1++;
			}
		}
		else if(cnt1<cnt2){
			if(a==1) a=1;
			else if(a%2) a=(a+1)/2;
			else a/=2;
			cnt1++;
		}
		else{
			if(b==1) b=1;
			else if(b%2) b=(b+1)/2;
			else b/=2;
			cnt2++;
		}
	}
}

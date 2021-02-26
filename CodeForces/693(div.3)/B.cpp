#include <cstdio>
#include <algorithm>
#include <cstdlib>
 
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, cnt=0, sum=0;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d", &tmp);
			if(tmp%2)
				cnt++;
			sum+=tmp;
		}
		if(sum%2)
			printf("NO\n");
		else{
			if(cnt==0 && n%2)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
}

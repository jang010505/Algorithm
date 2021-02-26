#include <cstdio>
#include <algorithm>
#include <cstdlib>
 
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int w, h, n;
		scanf("%d %d %d", &w, &h, &n);
		int cnt1=1, cnt2=1;
		while(w%2==0){
			cnt1*=2;
			w/=2;
		}
		while(h%2==0){
			cnt2*=2;
			h/=2;
		}
		if(cnt1*cnt2>=n)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, d[30001], answer=0, c0=0, c1=0, c2=0;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d", &d[i]);
			if(d[i]%3==0)
				c0++;
			else if(d[i]%3==1)
				c1++;
			else if(d[i]%3==2)
				c2++;
		}
		while(c1!=c2 || c2!=c0 || c1!=c0){
			if(c0>n/3){
				answer++;
				c0--;
				c1++;
			}
			if(c1>n/3){
				answer++;
				c1--;
				c2++;
			}
			if(c2>n/3){
				answer++;
				c2--;
				c0++;
			}
		}
		printf("%d\n", answer);
	}
}

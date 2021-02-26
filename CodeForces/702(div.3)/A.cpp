#include <algorithm>
 
using namespace std;
 
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, d[51], answer=0;
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d", &d[i]);
		for(int i=0;i<n-1;i++){
			int MIN=min(d[i], d[i+1]);
			int MAX=max(d[i], d[i+1]);
			if(MIN*2<MAX){
				while(MIN*2<MAX){
					answer++;
					MIN*=2;
				}
			}
		}
		printf("%d\n", answer);
	}	
}

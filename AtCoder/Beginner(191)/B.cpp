#include <cstdio>
 
using namespace std;
 
int main(){
	int n, x;
	scanf("%d %d", &n, &x);
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d", &tmp);
		if(x!=tmp)
			printf("%d ", tmp);		
	}
	return 0;
}

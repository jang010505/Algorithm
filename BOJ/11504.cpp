#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n, dp_up[1000]={}, dp_dwon[1000]={}, d[1000], answer=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(d[i]>d[j])
				dp_up[i]=max(dp_up[i], dp_up[j]+1);
			if(d[n-i-1]>d[n-j-1])
				dp_dwon[n-i-1]=max(dp_dwon[n-i-1], dp_dwon[n-j-1]+1);
		}
	}
	for(int i=0;i<n;i++)
		answer=max(answer, dp_up[i]+dp_dwon[i]);
	printf("%d", answer+1);
	return 0;
}

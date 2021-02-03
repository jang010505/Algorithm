#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll dist[1000000], gas[1000000]; 

int main(){
	int n;
	ll answer=0, gasmin;
	scanf("%d", &n);
	for(int i=0;i<n-1;i++)
		scanf("%lld", &dist[i]);
	for(int i=0;i<n;i++)
		scanf("%lld", &gas[i]);
	gasmin=gas[0];
	for(int i=0, j=0;i<n-1 && j<n-1;i++, j++){
		gasmin=min(gasmin, gas[j]);
		answer+=gasmin*dist[i];
	}
	printf("%lld", answer);
	return 0;
}

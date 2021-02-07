#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main(){
	long long answer=0, n, k;
	scanf("%lld %lld", &n, &k);
	queue <int> q[21];
	for(int i=0;i<n;i++){
		char name[100];
		scanf("%s", name);
		int l=strlen(name);
		while(q[l].empty()==0 && i-q[l].front()>k)
			q[l].pop();
		answer+=q[l].size();
		q[l].push(i);
	}
	printf("%lld", answer);
	return 0;
}

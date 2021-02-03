#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int n, d[1000000], answer[1000000];
stack<int> s;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	s.push(0);
	for(int i=1;i<n;i++){
		while(!s.empty() && d[s.top()]<d[i]){
			answer[s.top()]=d[i];
			s.pop();
		}
		s.push(i);
	}
	while(s.size()){
		answer[s.top()]=-1;
		s.pop();
	}
	for(int i=0;i<n;i++)
		printf("%d ", answer[i]);
	return 0;
}

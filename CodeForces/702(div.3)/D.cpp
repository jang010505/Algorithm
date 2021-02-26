#include <cstdio>
#include <algorithm>
#include <set>
 
using namespace std;
 
typedef long long ll;
 
void tree(int left, int right, int depth, int d[], int answer[]){
	if(left==right){
		answer[left]=depth;
		return;
	}
	if(left>right)
		return;
	int MAX=d[left];
	int index=left;
	for(int i=left;i<=right;i++){
		if(MAX<d[i]){
			MAX=d[i];
			index=i;
		}
	}
	answer[index]=depth;
	tree(left, index-1, depth+1, d, answer);
	tree(index+1, right, depth+1, d, answer);
}
	
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, d[100], answer[100];
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d", &d[i]);
		tree(0, n-1, 0, d, answer);
		for(int i=0;i<n;i++)
			printf("%d ", answer[i]);
		printf("\n");
	}
}

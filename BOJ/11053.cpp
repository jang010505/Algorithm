#include <iostream>
#include <algorithm>
using namespace std;
int n, d[1000], dp[1000], res=0;
int main(){
	cin >> n;
	for(int i=0;i<n;i++) cin >> d[i];
	for(int i=0;i<n;i++){
		int x=d[i];
		for(int j=0;j<i;j++){
			int y=d[j];
			if(x>y) dp[i]=max(dp[i], dp[j]+1);
		}
		res=max(res, dp[i]);
	}
	cout << res+1;
}

#include <iostream>
#include <algorithm>
using namespace std;
int n, d[2][100001], dp[2][100001], res=0, t;
int main(){
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n;
		for(int j=0;j<2;j++)
			for(int k=1;k<=n;k++)
				cin >> d[j][k];
		dp[0][0]=0;
		dp[1][0]=0;
		dp[0][1]=d[0][1];
		dp[1][1]=d[1][1];
		for(int j=2;j<=n;j++){
			dp[0][j]=max(dp[1][j-1], dp[1][j-2])+d[0][j];
			dp[1][j]=max(dp[0][j-1], dp[0][j-2])+d[1][j];
		}
		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
}

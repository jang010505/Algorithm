#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	str1='0'+str1;
	str2='0'+str2;
	int len1=str1.length();
	int len2=str2.length();
	int dp[1001][1001]={};
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			if(i==0 || j==0){
				dp[i][j]=0;
				continue;
			}
			if(str1[i]==str2[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << dp[len1-1][len2-1];
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n, d[101][101];
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> d[i][j];
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				d[i][j]=max(d[i][j], d[i][k]&d[k][j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(d[i][j]) cout << 1 << ' ';
			else cout << 0 <<' ';
		}
		cout <<'\n';
	}
}

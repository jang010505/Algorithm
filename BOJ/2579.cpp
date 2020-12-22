#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n, d[500], res[500];
	cin >> n;
	for(int i=0;i<n;i++) cin >> d[i];
	res[0]=d[0];
	res[1]=max(d[1], d[0]+d[1]);
	res[2]=max(d[0]+d[2], d[1]+d[2]);
	for(int i=3;i<n;i++) res[i]=max(res[i-2]+d[i], res[i-3]+d[i-1]+d[i]);
	cout << res[n-1];
}

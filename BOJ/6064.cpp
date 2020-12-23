#include <iostream>
using namespace std;
int gcd(int a, int b){
	if(b) return gcd(b, a%b);
	return a;
}
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		int res=y%(N+1);
		int X=y;
		for(int j=0;j<M;j++){
			int v=X%M==0 ? M:X%M;
			if(v==x) break;
			X=v+N;
			res+=N;
		}
		if(M*N/gcd(M, N)<res) cout << -1 << '\n';
		else cout << res << '\n';
	}
}

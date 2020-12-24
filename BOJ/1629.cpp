#include<algorithm>
#include<iostream>
using namespace std;
long long pow(int x, int y, int z){
	if(y==1) return x%z;
	if(y%2==0){
		long long int res=pow(x, y/2, z);
		return (res*res)%z;
	}
	else{
		long long int res1=pow(x, y/2, z), res2=pow(x, y/2+1, z);
		return (res1*res2)%z;
	}
}
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << pow(a, b, c);
}

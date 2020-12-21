#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long int> > operator * (const vector<vector<long long int> > &a, const vector<vector<long long int> > &b) {
    long long int size=a.size();
    vector<vector<long long int> > res(size, vector<long long int>(size));
    for (long long int i=0;i<size;i++) {
        for (long long int j=0;j<size;j++) {
            for (long long int k=0;k<size;k++) {
                res[i][j]+=a[i][k]*b[k][j];
            }
            res[i][j]%=1000000007;
        }
    }
    return res;
}
vector<vector<long long int> > power(vector<vector<long long int> > a, long long int n) {
   long long int size = a.size();
   vector<vector<long long int> > res(size, vector<long long int>(size));
   for(long long int i=0;i<size;i++) res[i][i]=1;
   while(n>0){
      if(n%2==1) res=res*a;
      n/=2;
      a=a*a;
   }
   return res;
} 
int main(){
   long long int n;
   cin >> n;
   vector<vector<long long int> > a={{1, 1}, {1, 0}};
   vector<vector<long long int> > res=(power(a, n-1));
   cout << (res[1][0]+res[1][1])%1000000007;
   return 0;
}

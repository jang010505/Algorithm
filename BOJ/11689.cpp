#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, ll> m;

int main()
{
   ll n;
   scanf("%lld", &n);
   if(n==1){
      printf("1");
      return 0;
   }
   ll i=2;
   while(i*i<=n){
   	  if(n%i==0){
         m[i]++;
         n/=i;
         continue;
      }
      i++;
   }
   m[n]++;
   ll answer=1;
   for(auto x=m.begin();x!=m.end();x++)
      answer*=pow(x->first, x->second)-pow(x->first, x->second-1);
   printf("%lld", answer);
   return 0;
}

#include<iostream>
#include<queue>
#include<set> 

using namespace std;

long long int A, B, C;
set<pair<pair<long long int, long long int>, long long int> > visit;

int main(){
   cin >> A >> B >> C;
   int res=0;
   queue<pair<pair<long long int, long long int>, long long int> > q;
   q.push(make_pair(make_pair(A, B), C));
   visit.insert(make_pair(make_pair(A, B), C)); 
   while(q.empty()==0){
      long long int a=q.front().first.first;
      long long int b=q.front().first.second;
      long long int c=q.front().second;
      q.pop();
      if(a==b && b==c && a==c){
         res=1;
         break;
      }
 	  long long int tmp_A, tmp_B, tmp_C;
      if(a<b){
         tmp_B=b-a;
         tmp_A=a*2;
      	 tmp_C=c;
         if(visit.find(make_pair(make_pair(tmp_A, tmp_B), tmp_C))==visit.end()){
            visit.insert(make_pair(make_pair(tmp_A, tmp_B), tmp_C));
            q.push(make_pair(make_pair(tmp_A, tmp_B), tmp_C));
         }
      }
      if(a>b){
         tmp_A=a-b;
         tmp_B=b*2;
         tmp_C=c;
         if(visit.find(make_pair(make_pair(tmp_A, tmp_B), tmp_C))==visit.end()){
            visit.insert(make_pair(make_pair(tmp_A, tmp_B), tmp_C));
            q.push(make_pair(make_pair(tmp_A, tmp_B), tmp_C));
         }
      }
      if(a<c){
         tmp_C=c-a;
         tmp_A=a*2;
         tmp_B=b;
         if(visit.find(make_pair(make_pair(tmp_A, tmp_B), tmp_C))==visit.end()){
            visit.insert(make_pair(make_pair(tmp_A, tmp_B), tmp_C));
            q.push(make_pair(make_pair(tmp_A, tmp_B), tmp_C));
         }
      }
      if(a>c){
         tmp_A=a-c;
         tmp_C=c*2;
         tmp_B=b;
         if(visit.find(make_pair(make_pair(tmp_A, tmp_B), tmp_C))==visit.end()){
            visit.insert(make_pair(make_pair(tmp_A, tmp_B), tmp_C));
            q.push(make_pair(make_pair(tmp_A, tmp_B), tmp_C));
         }
      }
      if(b<c){
      	 tmp_C=c-b;
         tmp_B=b*2;
         tmp_A=a;
         if(visit.find(make_pair(make_pair(tmp_A, tmp_B), tmp_C))==visit.end()){
            visit.insert(make_pair(make_pair(tmp_A, tmp_B), tmp_C));
            q.push(make_pair(make_pair(tmp_A, tmp_B), tmp_C));
         }
      }
      if(b>c){
         tmp_B=b-c;
         tmp_C=c*2;
         tmp_A=a;
         if(visit.find(make_pair(make_pair(tmp_A, tmp_B), tmp_C))==visit.end()){
            visit.insert(make_pair(make_pair(tmp_A, tmp_B), tmp_C));
            q.push(make_pair(make_pair(tmp_A, tmp_B), tmp_C));
         }
      }
   }    
   if(res) cout << 1;
   else cout << 0;
   return 0;
}

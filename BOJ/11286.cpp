#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;
int main(){
   int n;
   pair <int, int> temp;
   priority_queue<pair <int, int>, vector<pair <int, int> >, greater<pair <int, int> > > q;
   scanf("%d", &n);
   for(int i=0;i<n;i++){
   	int tmp;
      scanf("%d", &tmp);
      if(tmp==0){
         if(q.empty()) printf("0\n");
         else{
            temp=q.top();
            printf("%d\n", temp.second);
            q.pop();
         }
      }
      else q.push(make_pair(abs(tmp), tmp));
   }
   return 0;
}

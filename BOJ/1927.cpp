#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int main(){
   int n;
   scanf("%d",&n);
   priority_queue<int, vector<int>, greater<int> > q; 
   for(int i=0;i<n;i++){
      int tmp;
      scanf("%d",&tmp);
      if(tmp == 0){
         if(q.empty()) printf("0\n");
         else{
            printf("%d\n",q.top());
            q.pop();        
         }
      }
      else q.push(tmp);
   }
   return 0;
}

#include<iostream>
#include<queue>
using namespace std;
int n, m;
int d[300][300];
int visit[300][300];
int dx[]={ 0, 1 };
int dy[]={ 1, 0 };
int main(){
   cin >> n >> m;
   for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        	cin >> d[i][j];
   queue<pair<pair<int, int>, int> > q;
   q.push(make_pair(make_pair(0, 0), 0));
   visit[0][0]=1;
   while(q.empty()==0){
      int x=q.front().first.first;
      int y=q.front().first.second;
      int cnt=q.front().second;
      q.pop();
      if(x==n-1 && y==m-1){
         cout << cnt;
         return 0;
      }
      for(int i=0;i<2;i++){
         for(int k=1;k<=d[x][y];k++){
            int nx=x+dx[i]*k;
            int ny=y+dy[i]*k;
            if(nx>=0 && ny>=0 && nx<n && ny<m){
               if(visit[nx][ny]==0){
            		visit[nx][ny]=1;
               	q.push(make_pair(make_pair(nx, ny), cnt+1));
               }
            }
         }
      }
   }
   return 0;
}

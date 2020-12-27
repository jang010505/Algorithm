#include<iostream>
#include<queue>
using namespace std;
int N, M, H, W, Sx, Sy, Ex, Ey;
int MAP[1000][1000];
bool Visit[1000][1000];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool f(int x, int y, int dir){
   if(dir==0){
      int ny=y+W-1;
      if(ny>=M) return false;
      for(int i=x;i<x+H;i++){
         if(MAP[i][ny]==1)
				return false;
		}
   }
   else if(dir==1){
   	for(int i=x;i<x+H;i++){
      	if(MAP[i][y]==1)
				return false;
		}
	}
   else if(dir==2){
      int nx=x+H-1;
      if(nx>=N) return false;
      for (int i=y;i<y+W;i++){
         if(MAP[nx][i]==1)
				return false;
      }
   }
   else if(dir==3){
      for(int i=y;i<y+W;i++){
         if(MAP[x][i]==1)
				return false;
      }
   }
   return true;
}
int main(){
	cin >> N >> M;
   for(int i=0;i<N;i++)
      for(int j=0;j<M;j++)
         cin >> MAP[i][j];
   cin >> H >> W >> Sx >> Sy >> Ex >> Ey;
   Sx--; Sy--; Ex--; Ey--;
   queue<pair<pair<int, int>, int> > Q;
   Q.push(make_pair(make_pair(Sx, Sy), 0));
   Visit[Sx][Sy]=true;
   while(Q.empty()==0){
      int x=Q.front().first.first;
      int y=Q.front().first.second;
      int Cnt=Q.front().second;
      Q.pop();
      if(x==Ex && y==Ey){
         cout << Cnt;
         return 0;
      }
      for(int i=0;i<4;i++){
         int nx=x+dx[i];
         int ny=y+dy[i];
         if(nx>=0 && ny>= 0 && nx<N && ny<M){
            if(Visit[nx][ny]==false){
            	if(f(nx, ny, i)==true){
                  Visit[nx][ny]=true;
                  Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
               }
         	}
         }
      }
   }
   cout << -1;
   return 0;
}

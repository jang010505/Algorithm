#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double max_n, now_n;
int d[55], cnt[55], n, MAX=0;
void go(int x, int y){
    if(y>n) return;
    now_n=(double)(d[y]-d[x])/(y-x);
    if(now_n>max_n){
        max_n=now_n;
        cnt[x]++;
        cnt[y]++;
    }
    go(x, y+1);
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> d[i];
    for(int i=1;i<n;i++){
        max_n=-2000000000;
        go(i, i+1);
    }
    for(int i=1;i<=n;i++)
        MAX=max(MAX, cnt[i]);
    cout << MAX;
    return 0;
}

#include <stdio.h>
int n, d[20], s, cnt=0;
int f(int res, int j, int z){
	if(z && res==s) cnt++;
	for(int i=j+1;i<n;i++) f(res+d[i], i, 1);
	return 0;
}
int main(){
	scanf("%d %d", &n, &s);
	for(int i=0;i<n;i++) scanf("%d", &d[i]);
	f(0, -1, 0);	
	printf("%d", cnt);
}

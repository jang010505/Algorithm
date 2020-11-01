#include <stdio.h>
#include <stdlib.h>
char d[30][30];
int res[1000], cnt=0, n, cnt1=0;
int g(const void* a, const void* b){
	if(*(int*)a>*(int*)b) return 1;
	else if(*(int*)a<*(int*)b) return -1;
	else return 0;
}
int f(int i, int j){
	if(d[i][j]=='1'){
		cnt1++;
		d[i][j]='0';
		f(i-1, j);
		f(i+1, j);
		f(i, j-1);
		f(i, j+1);
	}
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%s", &d[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(d[i][j]=='1'){
				cnt1=0;
				f(i, j);
				res[cnt]=cnt1;
				cnt++;
			}
		}
	}
	qsort(res, cnt, sizeof(int), g);
	printf("%d\n", cnt);
	for(int i=0;i<cnt;i++) printf("%d\n", res[i]);
}

#include <stdio.h>

int main(){
	long long int n, m, l, d[500][500], res, min=257, max=0, min_time=9223372036854775807;
	scanf("%lld %lld %lld", &n, &m, &l);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%lld", &d[i][j]);
			if(d[i][j]>max) max=d[i][j];
			if(d[i][j]<min) min=d[i][j];
		}
	}
	for(int i=min;i<=max;i++){
		int cnt1=0, cnt2=0;
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(d[j][k]>i) cnt1+=d[j][k]-i;
				if(d[j][k]<i) cnt2+=i-d[j][k];
			}
		}
		if(l+cnt1>=cnt2){
			if(min_time>=cnt1*2+cnt2){
				min_time=cnt1*2+cnt2;
				res=i;
			}
		}
	}
	printf("%lld %lld", min_time, res);
}

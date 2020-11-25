#include <stdio.h>

int main(){
	long long int n, d[6], min1=51, max=0, min2=101, min3=151, v[8], s[12], res=0;
	scanf("%lld", &n);
	for(int i=0;i<6;i++){
		scanf("%lld", &d[i]);
		if(min1>d[i]) min1=d[i];
		if(max<d[i]) max=d[i];
		res+=d[i];
	}
	if(n==1){
		printf("%lld", res-max);
		return 0;
	}
	v[0]=d[0]+d[1]+d[2];
	v[1]=d[0]+d[1]+d[3];
	v[2]=d[0]+d[2]+d[4];
	v[3]=d[0]+d[3]+d[4];
	v[4]=d[5]+d[1]+d[2];
	v[5]=d[5]+d[1]+d[3];
	v[6]=d[5]+d[2]+d[4];
	v[7]=d[5]+d[3]+d[4];
	s[0]=d[0]+d[1];
	s[1]=d[0]+d[2];
	s[2]=d[0]+d[3];
	s[3]=d[0]+d[4];
	s[4]=d[2]+d[4];
	s[5]=d[1]+d[2];
	s[6]=d[1]+d[3];
	s[7]=d[3]+d[4];
	s[8]=d[5]+d[1];
	s[9]=d[5]+d[2];
	s[10]=d[5]+d[3];
	s[11]=d[5]+d[4];
	res=0;
	for(int i=0;i<8;i++) if(min3>v[i]) min3=v[i];
	for(int i=0;i<12;i++) if(min2>s[i]) min2=s[i];
	res+=min3*4;
	res+=min2*4;
	if(n>2){
		n-=2;
		res+=min1*5*n*n;
		res+=min1*4*n;
		res+=min2*8*n;
	}
	printf("%lld", res);
}

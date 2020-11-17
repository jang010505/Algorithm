#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	long long int d[2][10]={}, res=0;
	for(int i=0;i<10;i++){
		d[0][i]=i;
		d[1][i]=pow(10, i);
	}
	for(int i=0;i<3;i++){
		char s[100];
		scanf("%s", s);
		if(strcmp(s, "black")==0){
			if(i==0) res+=d[0][0]*10;
			if(i==1) res+=d[0][0];
			if(i==2) res*=d[1][0];
		}
		else if(strcmp(s, "brown")==0){
			if(i==0) res+=d[0][1]*10;
			if(i==1) res+=d[0][1];
			if(i==2) res*=d[1][1];
		}
		else if(strcmp(s, "red")==0){
			if(i==0) res+=d[0][2]*10;
			if(i==1) res+=d[0][2];
			if(i==2) res*=d[1][2];
		}
		else if(strcmp(s, "orange")==0){
			if(i==0) res+=d[0][3]*10;
			if(i==1) res+=d[0][3];
			if(i==2) res*=d[1][3];
		}
		else if(strcmp(s, "yellow")==0){
			if(i==0) res+=d[0][4]*10;
			if(i==1) res+=d[0][4];
			if(i==2) res*=d[1][4];
		}
		else if(strcmp(s, "green")==0){
			if(i==0) res+=d[0][5]*10;
			if(i==1) res+=d[0][5];
			if(i==2) res*=d[1][5];
		}
		else if(strcmp(s, "blue")==0){
			if(i==0) res+=d[0][6]*10;
			if(i==1) res+=d[0][6];
			if(i==2) res*=d[1][6];
		}
		else if(strcmp(s, "violet")==0){
			if(i==0) res+=d[0][7]*10;
			if(i==1) res+=d[0][7];
			if(i==2) res*=d[1][7];
		}
		else if(strcmp(s, "grey")==0){
			if(i==0) res+=d[0][8]*10;
			if(i==1) res+=d[0][8];
			if(i==2) res*=d[1][8];
		}
		else if(strcmp(s, "white")==0){
			if(i==0) res+=d[0][9]*10;
			if(i==1) res+=d[0][9];
			if(i==2) res*=d[1][9];
		}
	}
	printf("%lld", res);
}

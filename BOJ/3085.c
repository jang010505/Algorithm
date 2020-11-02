#include <stdio.h>
char d[55][55];
int main(){
	int n, max=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%s", d[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i>0){
				int temp=d[i][j], cnt=0;
				d[i][j]=d[i-1][j];
				d[i-1][j]=temp;
				for(int k=j;k<n;k++){
					if(d[i-1][j]==d[i-1][k]) cnt++;
					else break;
				}
				for(int k=j;k>=0;k--){
					if(d[i-1][j]==d[i-1][k]) cnt++;
					else break;
				}
				if(max<cnt) max=cnt-1;
				cnt=0;
				for(int k=i-1;k<n;k++){
					if(d[i-1][j]==d[k][j]) cnt++;
					else break;
				}
				for(int k=i-1;k>=0;k--){
					if(d[i-1][j]==d[k][j]) cnt++;
					else break;
				}
				if(max<cnt) max=cnt-1;
				temp=d[i-1][j];
				d[i-1][j]=d[i][j];
				d[i][j]=temp;
			}
			if(j>0){
				int temp=d[i][j], cnt=0;
				d[i][j]=d[i][j-1];
				d[i][j-1]=temp;
				for(int k=j-1;k<n;k++){
					if(d[i][j-1]==d[i][k]) cnt++;
					else break;
				}
				for(int k=j-1;k>=0;k--){
					if(d[i][j-1]==d[i][k]) cnt++;
					else break;
				}
				if(max<cnt) max=cnt-1;
				cnt=0;
				for(int k=i;k<n;k++){
					if(d[i][j-1]==d[k][j-1]) cnt++;
					else break;
				}
				for(int k=i;k>=0;k--){
					if(d[i][j-1]==d[k][j-1]) cnt++;
					else break;
				}
				if(max<cnt) max=cnt-1;
				temp=d[i][j];
				d[i][j]=d[i][j-1];
				d[i][j-1]=temp;
			}
			if(i+1<n){
				int temp=d[i][j], cnt=0;
				d[i][j]=d[i+1][j];
				d[i+1][j]=temp;
				for(int k=j;k<n;k++){
					if(d[i+1][j]==d[i+1][k]) cnt++;
					else break;
				}
				for(int k=j;k>=0;k--){
					if(d[i+1][j]==d[i+1][k]) cnt++;
					else break;
				}
				if(max<cnt) max=cnt-1;
				cnt=0;
				for(int k=i+1;k<n;k++){
					if(d[i+1][j]==d[k][j]) cnt++;
					else break;
				}
				for(int k=i+1;k>=0;k--){
					if(d[i+1][j]==d[k][j]) cnt++;
					else break;
				}
				if(max<cnt) max=cnt-1;
				temp=d[i+1][j];
				d[i+1][j]=d[i][j];
				d[i][j]=temp;
			}
			if(j+1<n){
				int temp=d[i][j], cnt=0;
				d[i][j]=d[i][j+1];
				d[i][j+1]=temp;
				for(int k=j+1;k<n;k++){
					if(d[i][j+1]==d[i][k]) cnt++;
					else break;
				}
				for(int k=j+1;k>=0;k--){
					if(d[i][j+1]==d[i][k]) cnt++;
					else break;
				}
				if(max<cnt) max=cnt-1;
				cnt=0;
				for(int k=i;k<n;k++){
					if(d[i][j+1]==d[k][j+1]) cnt++;
					else break;
				}
				for(int k=i;k>=0;k--){
					if(d[i][j+1]==d[k][j+1]) cnt++;
					else break;
				}
				if(max<cnt) max=cnt-1;
				temp=d[i][j];
				d[i][j]=d[i][j+1];
				d[i][j+1]=temp;
			}
		}
	}
	printf("%d", max);
}

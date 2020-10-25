#include <stdio.h>
#include <string.h>

int main(){
	int n, i, j;
	scanf("%d", &n);
	for(i=0;i<n*2-1;i++){
		if(i==0 || i==n*2-2){
			for(j=0;j<n;j++) printf("*");
			for(j=0;j<n*2-3;j++) printf(" ");
			for(j=0;j<n;j++) printf("*");
			printf("\n");
		}
		else if(i==n-1){
			for(j=0;j<n-1;j++) printf(" ");
			printf("*");
			for(j=0;j<n-2;j++) printf(" ");
			printf("*");
			for(j=0;j<n-2;j++) printf(" ");
			printf("*\n");
		}
		else{
			if(i<n-1){
				for(j=0;j<i;j++) printf(" ");
				printf("*");
				for(j=0;j<n-2;j++) printf(" ");
				printf("*");
				for(j=0;j<(n-i)*2-3;j++) printf(" ");
				printf("*");
				for(j=0;j<n-2;j++) printf(" ");
				printf("*\n");
			}
			else{
				for(j=0;j<(n-1)*2-i;j++) printf(" ");
				printf("*");
				for(j=0;j<n-2;j++) printf(" ");
				printf("*");
				for(j=0;j<(i-n)*2+1;j++) printf(" ");
				printf("*");
				for(j=0;j<n-2;j++) printf(" ");
				printf("*\n");
			}
		}
	}
}

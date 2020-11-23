#include <stdio.h>

typedef struct result{
	int y;
	int x1;
	int x2;
}res;
int main(){
	int n, s=0;
	res ans[10000];
	res *ptr[10000];
	res *temp;
	for(int i=0;i<10000;i++) ptr[i]=&ans[i];
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d %d %d", &ans[i].y, &ans[i].x1, &ans[i].x2);
	for(int i=1;i<n;i++){
		int c=i;
		do{
			int r=(c-1)/2;
			if(ptr[r]->y<ptr[c]->y){
				temp=ptr[r];
				ptr[r]=ptr[c];
				ptr[c]=temp;
			}
			c=r;
		}while(c!=0);
	}
	for(int i=n-1;i>=0;i--){
		int c, r=0;
		temp=ptr[0];
		ptr[0]=ptr[i];
		ptr[i]=temp;
		do{
			c=2*r+1;
			if(ptr[c]->y < ptr[c+1]->y && c<i-1) c++;
			if(ptr[r]->y < ptr[c]->y && c<i){
				temp=ptr[r];
				ptr[r]=ptr[c];
				ptr[c]=temp;
			}
			r=c;
		}while(c<i);
	}
	for(int i=n-1;i>=0;i--){
		int z=1;
		if(ptr[i]->y==1){
			s+=2;
			continue;
		}
		for(int j=i-1;j>=0;j--){
			if(ptr[j]->x1 <= ptr[i]->x1 && ptr[j]->x2 > ptr[i]->x1 && ptr[i]->y != ptr[j]->y){
				s+=ptr[i]->y-ptr[j]->y;
				z=0;
				break;
			}
		}
		if(z) s+=ptr[i]->y;
		z=1;
		for(int j=i-1;j>=0;j--){
			if(ptr[j]->x1 < ptr[i]->x2 && ptr[j]->x2 >= ptr[i]->x2 && ptr[i]->y != ptr[j]->y){
				s+=ptr[i]->y-ptr[j]->y;
				z=0;
				break;
			}
		}
		if(z) s+=ptr[i]->y;
	}
	printf("%d", s);
}

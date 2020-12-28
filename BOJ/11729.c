#include <stdio.h>
#include <math.h>

void hanoi(int i, int x, int y, int z){
	if(i==1)
		printf("%d %d\n", x, z);
	else{
		hanoi(i-1, x, z, y);
		printf("%d %d\n", x, z);
		hanoi(i-1, y, x, z);
	}
}
int main(){
	int n, count;
	scanf("%d", &n);
	count=pow(2, n)-1;
	printf("%d\n", count);
	hanoi(n, 1, 2, 3);
	return 0;
}

#include <stdio.h>
#include <math.h>

int main(){
	int n, m, x1, y1, x2, y2, rx, ry, r, cnt=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &m);
		cnt=0;
		for(int j=0;j<m;j++){
			scanf("%d %d %d", &rx, &ry, &r);
			if(pow(rx-x1, 2)+pow(ry-y1, 2)<pow(r, 2) && pow(rx-x2, 2)+pow(ry-y2, 2)>pow(r, 2)) cnt++;
			if(pow(rx-x1, 2)+pow(ry-y1, 2)>pow(r, 2) && pow(rx-x2, 2)+pow(ry-y2, 2)<pow(r, 2)) cnt++;
		}
		printf("%d\n", cnt);
	}
}

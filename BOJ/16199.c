#include <stdio.h>

int main(){
	int y1, m1, d1, y2, m2, d2;
	scanf("%d %d %d", &y1, &m1, &d1);
	scanf("%d %d %d", &y2, &m2, &d2);
	if(m1<=m2){
		if(m1==m2 && d1>d2) printf("%d\n%d\n%d", y2-y1-1, y2-y1+1, y2-y1);
	    else printf("%d\n%d\n%d", y2-y1, y2-y1+1, y2-y1);
    }
	else printf("%d\n%d\n%d", y2-y1-1, y2-y1+1, y2-y1);
}

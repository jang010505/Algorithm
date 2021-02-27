#include <cstdio>
 
using namespace std;
 
int main(){
	int v, t, s, d;
	scanf("%d %d %d %d", &v, &t, &s, &d);
	if(v*t<=d && d<=v*s)
		printf("No");
	else
		printf("Yes");
	return 0;
}

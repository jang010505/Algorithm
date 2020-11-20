#include <stdio.h>
int main(void)
{
	int n;
    scanf("%d", &n);
	char a[100];
    scanf("%s", a);
	long long int r=1, res=0;
	for (int i = 0;i<n; i++){
		res=(res+(a[i]-96)*r)%1234567891;
		r=(r*31)%1234567891;
	}
    printf("%lld", res);
	return 0;
}

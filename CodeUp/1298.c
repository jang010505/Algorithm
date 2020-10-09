#include <stdio.h>

long long int gcd(long long int x, long long int y){
	if(y==0) return x;
	else return gcd(y, x%y);
}
int main()
{
   	long long int a, b, c, res;
    	scanf("%lld %lld %lld", &a, &b, &c);
    	if(a==0 && b==0 && c!=0){
        	printf("Not Exist");
        	return 0;
    	}
    	res=gcd(a, b);
    	if(a==0 && b==0 && c==0){
		printf("0 0");
		return 0;
	}
    	if(c%res!=0){
        	printf("Not Exist");
    	}
    	else{
        	long long int r0=a, r1=b, s0=1, s1=0, t0=0, t1=1, t, q;
    		while(r1){
        		q=r0/r1;
        		t=r0;
        		r0=r1;
        		r1=t-r1*q;
        		t=s0;
        		s0=s1;
        		s1=t-s1*q;
        		t=t0;
        		t0=t1;
        		t1=t-t1*q;
    		}
    		printf("%lld %lld", s0*c/res, t0*c/res);
    	}
	return 0;
}

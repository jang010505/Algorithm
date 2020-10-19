#include<stdio.h>
#include<string.h>

int main(){
    double h,w,t;
    double ans1,ans2,ans3,a,b,c,d;
    scanf("%lf %lf",&h,&w);
    if(h<w){
        t=h;
        h=w;
        w=t;
    }
    a=1.0*h/3;
    if(a>w) ans1=w;
    else ans1=a;
    b=1.0*w/3;
    if(b>h) ans3=h;
    else ans3=b;
    if(ans1<ans3)
        ans1=ans3;
    a=1.0*w/3;
    c=1.0*h/2;
    d=1.0*w/2;
    if(c>d) ans2=d;
    else ans2=c;
    if(ans1>ans2) printf("%.3lf\n",ans1);
    else printf("%.3lf\n",ans2);
    return 0;
}

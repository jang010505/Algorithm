#include <cstdio>
#include <cmath>

using namespace std;

double dist(double dx, double dy){
	return dx*dx+dy*dy;
}

int main(){
	double x[301], y[301], x_sum=0, y_sum=0;
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%lf %lf", &x[i], &y[i]);
		x_sum+=x[i];
		y_sum+=y[i];
	}
	double now_x=x_sum/n;
	double now_y=y_sum/n;
	double tmp=0.1, distance;
	for(int i=0;i<50000;i++){
		int index=0;
		distance=dist(now_x-x[0], now_y-y[0]);
		for(int j=1;j<n;j++){
			double distance_tmp=dist(now_x-x[j], now_y-y[j]);
			if(distance<distance_tmp){
				distance=distance_tmp;
				index=j;
			}
		}
		now_x+=(x[index]-now_x)*tmp;
		now_y+=(y[index]-now_y)*tmp;
		tmp*=0.998;
	}
	printf("%.2lf", sqrt(distance)*2);
	return 0;
}

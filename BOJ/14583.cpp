#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    double H, V;
    scanf("%lf %lf", &H, &V);
    double D = sqrt(H * H + V * V);
    double x = (V * V - (D - H) * (D - H)) / (2 * V);
    double l = sqrt(x * x + H * H);
    printf("%.2f %.2f", l / 2, D * x / l);
    return 0;
}
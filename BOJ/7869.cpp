#include <cstdio>
#include <cmath>

using namespace std;

typedef struct
{
    double x;
    double y;
    double r;
} Circle;

int main()
{
    Circle c1, c2;
    double answer;
    double pi = 3.14159265358979f;
    scanf("%lf %lf %lf", &c1.x, &c1.y, &c1.r);
    scanf("%lf %lf %lf", &c2.x, &c2.y, &c2.r);
    double d = sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
    if ((c1.r + c2.r) < d)
        answer = 0;
    else if (d <= fabs(c1.r - c2.r) && c1.r >= c2.r)
        answer = pi * c2.r * c2.r;
    else if (d <= fabs(c1.r - c2.r) && c2.r > c1.r)
        answer = pi * c1.r * c1.r;
    else
    {
        double phi = (acos((c1.r * c1.r + d * d - c2.r * c2.r) / (c1.r * 2 * d))) * 2;
        double theta = (acos((c2.r * c2.r + d * d - c1.r * c1.r) / (c2.r * 2 * d))) * 2;
        answer = (theta * c2.r * c2.r) / 2 - (c2.r * c2.r * sin(theta)) / 2 + (phi * c1.r * c1.r) / 2 - (c1.r * c1.r * sin(phi)) / 2;
    }
    answer = round(answer * 1000) / 1000;
    printf("%.3lf", answer);
    return 0;
}
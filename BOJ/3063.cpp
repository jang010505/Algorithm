#include <cstdio>

using namespace std;

typedef struct
{
    int x1, x2;
    int y1, y2;
} Rectangle;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        Rectangle r1, r2;
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &r1.x1, &r1.y1, &r1.x2, &r1.y2);
        scanf("%d %d %d %d", &r2.x1, &r2.y1, &r2.x2, &r2.y2);
        if (r2.x2 <= r1.x1 || r1.x2 <= r2.x1 || r2.y2 <= r1.y1 || r1.y2 <= r2.y1)
        {
            printf("%d\n", (r1.x2 - r1.x1) * (r1.y2 - r1.y1));
            continue;
        }
        if (r2.x1 <= r1.x1)
            x1 = r1.x1;
        else
            x1 = r2.x1;
        if (r2.x2 <= r1.x2)
            x2 = r2.x2;
        else
            x2 = r1.x2;
        if (r2.y1 <= r1.y1)
            y1 = r1.y1;
        else
            y1 = r2.y1;
        if (r2.y2 <= r1.y2)
            y2 = r2.y2;
        else
            y2 = r1.y2;
        printf("%d\n", (r1.x2 - r1.x1) * (r1.y2 - r1.y1) - (x2 - x1) * (y2 - y1));
    }
}
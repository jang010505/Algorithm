#include <cstdio>

using namespace std;

int main()
{
    int n, k, d[4242] = {}, visit[4243] = {};
    scanf("%d %d", &n, &k);
    int start = 1, end = n;
    for (int i = 0; i < n; i++)
    {
        if (k >= n - 1 - i)
        {
            while (visit[end])
                end--;
            visit[end] = 1;
            d[i] = end--;
            k -= n - 1 - i;
        }
        else
        {
            while (visit[start])
                start++;
            d[i] = start++;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", d[i]);
    return 0;
}
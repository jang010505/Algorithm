#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, x, dp[10001] = {};
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++)
        dp[i] = 10001;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        for (int j = x; j <= k; j++)
            dp[j] = min(dp[j], dp[j - x] + 1);
    }
    if (dp[k] == 10001)
        printf("-1");
    else
        printf("%d", dp[k]);
}
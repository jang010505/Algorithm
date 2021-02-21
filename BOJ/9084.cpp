#include <cstdio>

using namespace std;

typedef long long ll;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, d[20], m, dp[10001] = {};
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &d[i]);
        scanf("%d", &m);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = d[i]; j <= m; j++)
                dp[j] += dp[j - d[i]];
        printf("%d\n", dp[m]);
    }
    return 0;
}
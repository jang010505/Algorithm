#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    int n, d[1000], m, dp[10001] = {};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &d[i]);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = d[i]; j <= m; j++)
            dp[j] += dp[j - d[i]];
    printf("%d\n", dp[m]);
    return 0;
}
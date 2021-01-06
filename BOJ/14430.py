n, m=map(int, input().split())
d=[]
dp=[[0]*m for i in range(n)]
for i in range(n):
    d.append(list(map(int, input().split())))
dp[0][0]=d[0][0]
for i in range(n):
    for j in range(m):
        if j+1<m and d[i][j+1]:
            dp[i][j+1]=max(dp[i][j]+1, dp[i][j+1])
        elif j+1<m:
            dp[i][j+1]=max(dp[i][j], dp[i][j+1])
        if i+1<n and d[i+1][j]:
            dp[i+1][j]=max(dp[i][j]+1, dp[i+1][j])
        elif i+1<n:
            dp[i+1][j]=max(dp[i][j], dp[i+1][j])
print(dp[n-1][m-1])

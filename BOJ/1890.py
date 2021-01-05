n=int(input())
list_x=[]
dp=[[0]*n for i in range(n)]
for i in range(n):
    list_x.append(list(map(int, input().split())))
dp[0][0]=1
for i in range(n):
    for j in range(n):
        if dp[i][j]==0 or i==j==n-1:
            continue
        jump=list_x[i][j]
        down=i+jump
        right=j+jump
        if down<n:
            dp[down][j]+=dp[i][j]
        if right<n:
            dp[i][right]+=dp[i][j]
print(dp[n-1][n-1])

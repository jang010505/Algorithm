from collections import deque
n=int(input())
list_x=[]
d=[[2, 0], [1, 1], [0, 2]]
for i in range(n):
    list_x.append(list(input().split()))
dp=[[[-10000, 100000] for j in range(n)] for i in range(n)]
dp[0][0][0]=int(list_x[0][0])
dp[0][0][1]=int(list_x[0][0])
q=deque()
q.append((0, 0))
while q:
    now_i, now_j=q.popleft()
    for k in range(3):
        i=now_i+d[k][0]
        j=now_j+d[k][1]
        if i<n and j<n:
            if k==0:
                q.append((i, j))
                if list_x[i-1][j]=='*':
                    dp[i][j][0]=max(dp[now_i][now_j][0]*int(list_x[i][j]), dp[i][j][0])
                    dp[i][j][1]=min(dp[now_i][now_j][1]*int(list_x[i][j]), dp[i][j][1])
                if list_x[i-1][j]=='+':
                    dp[i][j][0]=max(dp[now_i][now_j][0]+int(list_x[i][j]), dp[i][j][0])
                    dp[i][j][1]=min(dp[now_i][now_j][1]+int(list_x[i][j]), dp[i][j][1])
                if list_x[i-1][j]=='-':
                    dp[i][j][0]=max(dp[now_i][now_j][0]-int(list_x[i][j]), dp[i][j][0])
                    dp[i][j][1]=min(dp[now_i][now_j][1]-int(list_x[i][j]), dp[i][j][1])
            if k==1:
                q.append((i, j))
                if list_x[i-1][j]=='*':
                    dp[i][j][0]=max(dp[now_i][now_j][0]*int(list_x[i][j]), dp[i][j][0])
                    dp[i][j][1]=min(dp[now_i][now_j][1]*int(list_x[i][j]), dp[i][j][1])
                if list_x[i][j-1]=='*':
                    dp[i][j][0]=max(dp[now_i][now_j][0]*int(list_x[i][j]), dp[i][j][0])
                    dp[i][j][1]=min(dp[now_i][now_j][1]*int(list_x[i][j]), dp[i][j][1])
                if list_x[i-1][j]=='+':
                    dp[i][j][0]=max(dp[now_i][now_j][0]+int(list_x[i][j]), dp[i][j][0])
                    dp[i][j][1]=min(dp[now_i][now_j][1]+int(list_x[i][j]), dp[i][j][1])
                if list_x[i][j-1]=='+':
                    dp[i][j][0]=max(dp[now_i][now_j][0]+int(list_x[i][j]), dp[i][j][0])
                    dp[i][j][1]=min(dp[now_i][now_j][1]+int(list_x[i][j]), dp[i][j][1])
                if list_x[i-1][j]=='-':
                    dp[i][j][0]=max(dp[now_i][now_j][0]-int(list_x[i][j]), dp[i][j][0])
                    dp[i][j][1]=min(dp[now_i][now_j][1]-int(list_x[i][j]), dp[i][j][1])
                if list_x[i][j-1]=='-':
                    dp[i][j][0]=max(dp[now_i][now_j][0]-int(list_x[i][j]), dp[i][j][0])
                    dp[i][j][1]=min(dp[now_i][now_j][1]-int(list_x[i][j]), dp[i][j][1])
            if k==2:
                q.append((i, j))
                if list_x[i][j-1]=='*':
                    dp[i][j][0]=max(dp[now_i][now_j][0]*int(list_x[i][j]), dp[i][j][0])
                    dp[i][j][1]=min(dp[now_i][now_j][1]*int(list_x[i][j]), dp[i][j][1])
                if list_x[i][j-1]=='+':
                    dp[i][j][0]=max(dp[now_i][now_j][0]+int(list_x[i][j]), dp[i][j][0])
                    dp[i][j][1]=min(dp[now_i][now_j][1]+int(list_x[i][j]), dp[i][j][1])
                if list_x[i][j-1]=='-':
                    dp[i][j][0]=max(dp[now_i][now_j][0]-int(list_x[i][j]), dp[i][j][0])
                    dp[i][j][1]=min(dp[now_i][now_j][1]-int(list_x[i][j]), dp[i][j][1])
print(dp[n-1][n-1][0], dp[n-1][n-1][1])

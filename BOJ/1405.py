def dfs(now_i, now_j, x, cost):
    global n, result
    if cost==n:
        result+=x
        return
    for v in range(4):
        i=now_i+d[v][0]
        j=now_j+d[v][1]
        if visit[i][j]==0:
            visit[i][j]=1
            dfs(i, j, x*d2[v]/100, cost+1)
            visit[i][j]=0
n, E, W, S, N=map(int, input().split())
visit=[[0]*50 for i in range(50)]
d=[[1, 0], [0, 1], [-1, 0], [0, -1]]
d2=[S, E, N, W]
result=0
visit[25][25]=1
dfs(25, 25, 1, 0)
print(result)

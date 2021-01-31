n, m=map(int, input().split())
info=[[100000000]*(n+1) for i in range(n+1)]
for i in range(n+1):
    info[i][i]=0
for i in range(m):
    u, v, b=map(int, input().split())
    if b:
        info[u][v]=0
        info[v][u]=0
    else:
        info[u][v]=0
        info[v][u]=1
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            info[i][j]=min(info[i][j], info[i][k]+info[k][j])
for i in range(int(input())):
    start, end=map(int, input().split())
    print(info[start][end])

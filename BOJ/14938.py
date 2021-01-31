n, m, r=map(int, input().split())
info=[[100000000]*(n+1) for i in range(n+1)]
for i in range(n+1):
    info[i][i]=0
item=list(map(int, input().split()))
item.insert(0, 0)
for i in range(r):
    u, v, b=map(int, input().split())
    info[u][v]=b
    info[v][u]=b
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            info[i][j]=min(info[i][j], info[i][k]+info[k][j])
answer=0
for i in range(1, n+1):
    sum_t=0
    for j in range(1, n+1):
        if info[i][j]<=m:
            sum_t+=item[j]
    answer=max(answer, sum_t)
print(answer)

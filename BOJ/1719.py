n, m=map(int, input().split())
visit=[[100000000]*(n+1) for i in range(n+1)]
answer=[[0]*(n+1) for i in range(n+1)]
for i in range(1, n+1):
    visit[i][i]=0
for i in range(m):
    u, v, w=map(int, input().split())
    visit[u][v]=w
    visit[v][u]=w
    answer[u][v]=v
    answer[v][u]=u
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if visit[i][j]>visit[i][k]+visit[k][j]:
                visit[i][j]=visit[i][k]+visit[k][j]
                answer[i][j]=answer[i][k]
for i in range(1, n+1):
    for j in range(1, n+1):
        if i==j:
            print("-", end=' ')
        else:
            print(answer[i][j], end=' ')
    print()

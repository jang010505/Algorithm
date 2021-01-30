n=int(input())
m=int(input())
visit=[[100000000]*(n+1) for i in range(n+1)]
for i in range(1, n+1):
    visit[i][i]=0
for i in range(m):
    u, v, w=map(int, input().split())
    visit[u][v]=min(visit[u][v], w)
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if visit[i][j]>visit[i][k]+visit[k][j]:
                visit[i][j]=visit[i][k]+visit[k][j]
for i in range(1, n+1):
    for j in range(1, n+1):
        if visit[i][j]!=100000000:
            print(visit[i][j], end=' ')
        else:
            print(0, end=' ')
    print()

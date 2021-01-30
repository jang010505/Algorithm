n, m=map(int, input().split())
visit=[[100000000]*(n+1) for i in range(n+1)]
answer=[[0]*(n+1) for i in range(n+1)]
for i in range(1, n+1):
    visit[i][i]=0
for i in range(m):
    u, v, w=map(int, input().split())
    visit[u][v]=w
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if visit[i][j]>visit[i][k]+visit[k][j]:
                visit[i][j]=visit[i][k]+visit[k][j]
answer=100000000
for i in range(1, n):
    for j in range(i+1, n+1):
        if visit[i][j]!=100000000 and visit[j][i]!=100000000:
            answer=min(answer, visit[i][j]+visit[j][i])
if answer!=100000000:
    print(answer)
else:
    print(-1)

n, k=map(int, input().split())
info=[[10e8]*(n+1) for i in range(n+1)]
for i in range(k):
    a, b=map(int, input().split())
    info[a][b]=1
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            info[i][j]=min(info[i][j], info[i][k]+info[k][j])
for i in range(int(input())):
    a, b=map(int, input().split())
    if info[a][b]!=10e8:
        print(-1)
    elif info[b][a]!=10e8:
        print(1)
    else:
        print(0)

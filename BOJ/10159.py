n=int(input())
info=[[10e8]*(n+1) for i in range(n+1)]
for i in range(1, n+1):
    info[i][i]=0
    info[i][0]=0
    info[0][i]=0
for i in range(int(input())):
    a, b=map(int, input().split())
    info[a][b]=1
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            info[i][j]=min(info[i][j], info[i][k]+info[k][j])
for i in range(1, n):
    for j in range(i+1, n+1):
        if info[i][j]==10e8 and info[j][i]!=10e8:
            info[i][j]=info[j][i]
        if info[j][i]==10e8 and info[i][j]!=10e8:
            info[j][i]=info[i][j]
for i in range(1, n+1):
    print(info[i].count(10e8))

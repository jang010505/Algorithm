n, m=map(int, input().split())
info=[[100000000]*(n+1) for i in range(n+1)]
for i in range(1, n+1):
    info[i][i]=0
for i in range(m):
    a, b=map(int, input().split())
    info[a][b]=1 
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            info[i][j]=min(info[i][j], info[i][k]+info[k][j])
for i in range(1, n):
    for j in range(i+1, n+1):
        if info[i][j]!=100000000:
            info[j][i]=info[i][j]
        if info[j][i]!=100000000:
            info[i][j]=info[j][i]
answer=0
for i in range(1, n+1):
    chk=True
    for j in range(1, n+1):
        if i==j:
            continue
        elif info[i][j]==100000000:
            chk=False
            break
    if chk:
        answer+=1
print(answer)

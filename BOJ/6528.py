lst=list(map(int, input().split()))
while len(lst)==2:
    n, m=lst
    info=[[0]*(n+1) for i in range(n+1)]
    for i in range(1, n+1):
        info[i][i]=1
    for i in range(m):
        a, b, p=map(int, input().split())
        info[a][b]=p/100
        info[b][a]=p/100
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                info[i][j]=max(info[i][j], info[i][k]*info[k][j])
    print("%.6f percent"%(info[1][n]*100))
    lst=list(map(int, input().split()))

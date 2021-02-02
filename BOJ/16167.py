N, R=map(int, input().split())
info=[[10e9]*(N+1) for i in range(N+1)]
answer_cnt=[[10e9]*(N+1) for i in range(N+1)]
for i in range(1, N+1):
    info[i][i]=0
for i in range(R):
    a, b, c, d, e=map(int, input().split())
    cost=c
    if e-10>0:
        cost+=(e-10)*d
    info[a][b]=min(info[a][b], cost)
    answer_cnt[a][b]=2
for k in range(1, N+1):
    for i in range(1, N+1):
        for j in range(1, N+1):
            if info[i][j]>info[i][k]+info[k][j]:
                info[i][j]=info[i][k]+info[k][j]
                answer_cnt[i][j]=answer_cnt[i][k]+answer_cnt[k][j]-1
            elif info[i][j]==info[i][k]+info[k][j]:
                answer_cnt[i][j]=min(answer_cnt[i][j], answer_cnt[i][k]+answer_cnt[k][j]-1)
if info[1][N]!=10e9:
    print(info[1][N], answer_cnt[1][N])
else:
    print("It is not a great way.")

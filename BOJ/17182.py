from itertools import permutations
n, K=map(int, input().split())
info=list()
visit=[i for i in range(n)]
for i in range(n):
    info.append(list(map(int, input().split())))
for k in range(n):
    for i in range(n):
        for j in range(n):
            info[i][j]=min(info[i][j], info[i][k]+info[k][j])
answer=10e9
for lst in permutations(visit):
    if lst[0]==K:
        sum_tmp=0
        for i in range(n-1):
            sum_tmp+=info[lst[i]][lst[i+1]]
        answer=min(answer, sum_tmp)
print(answer)

n=int(input())
info=list()
answer=[[] for i in range(n)]
for i in range(n):
    info.append(list(map(int, input().split())))
    for j in range(n):
        answer[i].append(info[i][j])
for k in range(n):
    for i in range(n):
        for j in range(n):
            if i==k or j==k:
                continue
            if info[i][j]==info[i][k]+info[k][j]:
                answer[i][j]=0
            elif info[i][j]>info[i][k]+info[k][j]:
                print(-1)
                exit()
answer_sum=0
chk=[[1]*n for i in range(n)]
for i in range(n):
    for j in range(n):
        if answer[i][j]!=0 and chk[i][j]:
            answer_sum+=answer[i][j]
            chk[i][j]=0
            chk[j][i]=0
print(answer_sum)

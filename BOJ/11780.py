n=int(input())
info=[[10e8]*(n+1) for i in range(n+1)]
answer=list()
for i in range(n+1):
    answer.append([])
    for j in range(n+1):
        answer[i].append([])
for i in range(1, n+1):
    info[i][i]=0
for i in range(int(input())):
    a, b, c=map(int, input().split())
    info[a][b]=min(info[a][b], c)
    if len(answer[a][b])==0:
        answer[a][b].append(a)
        answer[a][b].append(b)
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if info[i][j]>info[i][k]+info[k][j]:
                info[i][j]=info[i][k]+info[k][j]
                answer[i][j].clear()
                for l in range(len(answer[i][k])):
                    answer[i][j].append(answer[i][k][l])
                for l in range(1, len(answer[k][j])):
                    answer[i][j].append(answer[k][j][l])
for i in range(1, n+1):
    for j in range(1, n+1):
        if 10e8==info[i][j] or i==j:
            print(0, end=' ')
        else:
            print(info[i][j], end=' ')
    print()
for i in range(1, n+1):
    for j in range(1, n+1):
        if len(answer[i][j])==0:
            print(0)
        else:
            print(len(answer[i][j]), end=' ')
            print(' '.join(map(str, answer[i][j])))

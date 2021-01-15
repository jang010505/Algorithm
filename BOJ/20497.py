def dfs(now_i, now_j, chk):
    global n
    for di, dj in d:
        i=now_i+di
        j=now_j+dj
        if 0<=i<n and 0<=j<n:
            if visit[i][j]!=chk and list_x[i][j]=='.':
                visit[i][j]=chk
                dfs(i, j, chk)
n=int(input())
list_x=list()
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
answer=0
for i in range(n):
    list_x.append(list(input()))
for i in range(n):
    for j in range(n):
        if list_x[i][j]=='.':
            list_x[i][j]='@'
            cnt=0
            visit=[[0]*n for i in range(n)]
            visit[i][j]=1
            dfs(i, j, 1)
            for I in range(n):
                for J in range(n):
                    if list_x[I][J]=='.' and visit[I][J]:
                        cnt+=1
                        visit[I][J]=0
                        dfs(I, J, 0)
            list_x[i][j]='.'
            if cnt>=2:
                answer+=1
print(answer)

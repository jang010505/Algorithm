def dfs(now_i, now_j, cost):
    global r, c, ans
    ans=max(ans, cost)
    if ans>=26:
        print(26)
        exit()
    for di, dj in d:
        i=now_i+di
        j=now_j+dj
        if 0<=i<r and 0<=j<c:
            if visit[ord(list_x[i][j])-65]==0:
                visit[ord(list_x[i][j])-65]=1
                dfs(i, j, cost+1)
                visit[ord(list_x[i][j])-65]=0
r, c=map(int, input().split())
list_x=[]
ans=0
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for i in range(r):
    list_x.append(list(input()))
visit=[0]*26
visit[ord(list_x[0][0])-65]=1
dfs(0, 0, 1)
print(ans)

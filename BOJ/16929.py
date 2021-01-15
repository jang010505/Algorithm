def dfs(now_i, now_j, prv_i, prv_j, taget):
    global n, m
    for di, dj in d:
        i=now_i+di
        j=now_j+dj
        if 0<=i<n and 0<=j<m:
            if not (i==prv_i and j==prv_j) and visit[i][j]==1 and list_x[i][j]==taget:
                print("Yes")
                exit()
            elif visit[i][j]==0 and list_x[i][j]==taget:
                visit[i][j]=1
                dfs(i, j, now_i, now_j, taget)
n, m=map(int, input().split())
list_x=list()
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for i in range(n):
    list_x.append(list(input()))
visit=[[0]*(m) for i in range(n)]
for i in range(n):
    for j in range(m):
        if visit[i][j]==0:
            visit[i][j]=1
            dfs(i, j, -1, -1, list_x[i][j])
print("No")

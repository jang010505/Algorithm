def dfs(now_i, now_j, count, string):
    if string in dict_x:
        dict_x[string]+=1
    if count==5:
        return
    for di, dj in d:
        i=now_i+di
        j=now_j+dj
        if i<0:
            i=n-1
        if i>=n:
            i=0
        if j<0:
            j=m-1
        if j>=m:
            j=0
        dfs(i, j, count+1, string+list_x[i][j])
n, m, k=map(int, input().split())
list_x=list()
list_y=list()
dict_x=dict()
d=[[1, 1], [1, 0], [1, -1], [0, 1], [0, -1], [-1, 1], [-1, 0], [-1, -1]]
for i in range(n):
    list_x.append(list(input()))
for i in range(k):
    tmp=input()
    list_y.append(tmp)
    dict_x.update({tmp:0})
for i in range(n):
    for j in range(m):
        dfs(i, j, 1, list_x[i][j])
for i in list_y:
    print(dict_x[i])

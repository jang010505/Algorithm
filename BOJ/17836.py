from collections import deque
n, m, t=map(int, input().split())
list_x=[]
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for i in range(n):
    list_x.append(list(map(int, input().split())))
    for j in range(m):
        if list_x[i][j]==2:
            sword_i, sword_j=i, j
q=deque()
q.append((0, 0))
visit=[[0]*m for i in range(n)]
visit[0][0]=1
while q:
    now_i, now_j=q.popleft()
    for k in d:
        i=now_i+k[0]
        j=now_j+k[1]
        if 0<=i<n and 0<=j<m:
            if list_x[i][j]!=1 and visit[i][j]==0:
                visit[i][j]=1+visit[now_i][now_j]
                q.append((i, j))
if visit[n-1][m-1]:
    if visit[n-1][m-1]>visit[sword_i][sword_j]+abs(n-sword_i-1)+abs(m-1-sword_j):
        if visit[sword_i][sword_j]+abs(n-sword_i-1)+abs(m-1-sword_j)-1<=t:
            print(visit[sword_i][sword_j]+abs(n-sword_i-1)+abs(m-1-sword_j)-1)
        else:
            print("Fail")
    else:
        if visit[n-1][m-1]-1<=t:
            print(visit[n-1][m-1]-1)
        else:
            print("Fail")
elif visit[sword_i][sword_j]:
    if visit[sword_i][sword_j]+abs(n-sword_i-1)+abs(m-1-sword_j)-1<=t:
        print(visit[sword_i][sword_j]+abs(n-sword_i-1)+abs(m-1-sword_j)-1)
    else:
        print("Fail")
else:
    print("Fail")

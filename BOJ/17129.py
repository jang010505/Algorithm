from collections import deque
import sys
n, m=map(int, input().split())
list_x=[]
d=[[1, 0], [-1, 0], [0, 1], [0, -1]]
visit=[[0]*m for i in range(n)]
for i in range(n):
    list_x.append(list(sys.stdin.readline()))
    for j in range(m):
        list_x[i][j]=int(list_x[i][j])
        if list_x[i][j]==2:
            start_i, start_j=i, j
q=deque()
q.append((start_i, start_j))
visit[start_i][start_j]=1
while q:
    now_i, now_j=q.popleft()
    for k in d:
        i=now_i+k[0]
        j=now_j+k[1]
        if 0<=i<n and 0<=j<m:
            if list_x[i][j]!=1 and visit[i][j]==0:
                visit[i][j]=1+visit[now_i][now_j]
                if list_x[i][j]!=0:
                    print("TAK")
                    print(visit[i][j]-1)
                    exit()
                q.append((i, j))
print("NIE")

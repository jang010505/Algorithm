from collections import deque
n, m, k=map(int, input().split())
visit=[[0]*m for i in range(n)]
for i in range(k):
    x1, y1, x2, y2=map(int, input().split())
    for j in range(y1, y2):
        for k in range(x1, x2):
            visit[j][k]=1
cnt=0
res=[]
x=[[1, 0], [-1, 0], [0, 1], [0, -1]]
for i in range(n):
    for j in range(m):
        if visit[i][j]==0:
            cnt+=1
            q=deque()
            q.append([i, j])
            visit[i][j]=1
            cost=1
            while q:
                q_pop=q.popleft()
                I=q_pop[0]
                J=q_pop[1]
                for k in x:
                    if 0<=I+k[0]<n and 0<=J+k[1]<m and visit[I+k[0]][J+k[1]]==0:
                        cost+=1
                        q.append([I+k[0], J+k[1]])
                        visit[I+k[0]][J+k[1]]=1
            res.append(cost)
print(cnt)
res.sort()
for i in res:
    print(i, end=' ')

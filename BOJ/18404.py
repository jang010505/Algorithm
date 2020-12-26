from collections import deque
n, m=map(int, input().split())
x, y=map(int, input().split())
d=[[2, 1], [2, -1], [-2, 1], [-2, -1], [1, 2], [1, -2], [-1, 2], [-1, -2]]
list_=[]
for _ in range(m):
    a, b=map(int, input().split())
    list_.append([a, b])
visit=[[0]*(n+1) for i in range(n+1)]
q=deque()
q.append([x, y, 1])
visit[x][y]=1
dp=[[1000]*(n+1) for i in range(n+1)]
while q:
    q_pop=q.popleft()
    i=q_pop[0]
    j=q_pop[1]
    cost=q_pop[2]
    for k in d:
        if 0<i+k[0]<=n and 0<j+k[1]<=n and visit[i+k[0]][j+k[1]]==0:
            q.append([i+k[0], j+k[1], cost+1])
            visit[i+k[0]][j+k[1]]=1
            if dp[i+k[0]][j+k[1]]>cost:
                dp[i+k[0]][j+k[1]]=cost
for i in range(m):
    print(dp[list_[i][0]][list_[i][1]], end=' ') 

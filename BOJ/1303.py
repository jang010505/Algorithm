from collections import deque
m, n=map(int, input().split())
x=[]
visit=[]
for i in range(n):
    visit.append([0]*m)
for i in range(n):
    x.append(list(input()))
res1, res2=0, 0
for I in range(n):
    for J in range(m):
        if visit[I][J]==0:
            q=deque()
            q.append([I, J])
            visit[I][J]=1
            cost=1
            while q:
                q_pop=q.popleft()
                i=q_pop[0]
                j=q_pop[1]
                if i-1>=0 and visit[i-1][j]==0 and x[i][j]==x[i-1][j]:
                    q.append([i-1, j])
                    visit[i-1][j]=1
                    cost+=1
                if j-1>=0 and visit[i][j-1]==0 and x[i][j]==x[i][j-1]:
                    q.append([i, j-1])
                    visit[i][j-1]=1
                    cost+=1
                if i+1<n and visit[i+1][j]==0 and x[i][j]==x[i+1][j]:
                    q.append([i+1, j])
                    visit[i+1][j]=1
                    cost+=1
                if j+1<m and visit[i][j+1]==0 and x[i][j]==x[i][j+1]:
                    q.append([i, j+1])
                    visit[i][j+1]=1
                    cost+=1
            if x[I][J]=='W': res1+=cost**2
            else: res2+=cost**2
print(res1, res2)

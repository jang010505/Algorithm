from collections import deque
n, k=map(int, input().split())
visit=[]
for i in range(2):
    visit.append(list(input()))
q=deque()
q.append([0, 0, 0])
chk=1
while q:
    q_pop=q.popleft()
    i=q_pop[0]
    j=q_pop[1]
    cost=q_pop[2]
    if j+1>=n or j+k>=n:
        chk=0
        break
    if cost<j+1 and visit[i][j+1]=='1':
        q.append([i, j+1, cost+1])
        visit[i][j+1]='0'
    if cost<j-1 and visit[i][j-1]=='1':
        q.append([i, j-1, cost+1])
        visit[i][j-1]='0'
    if cost<j+k and visit[abs(i-1)][j+k]=='1':
        q.append([abs(i-1), j+k, cost+1])
        visit[abs(i-1)][j+k]='0'
if chk: print(0)
else: print(1)

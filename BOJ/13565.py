from collections import deque
n, m=map(int, input().split())
visit=[]
x=[[1, 0], [-1,0], [0, 1], [0, -1]]
chk=1
for i in range(n):
    visit.append(list(input()))
for i in range(m):
    if visit[0][i]=='0':
        q=deque()
        q.append([0, i])
        visit[0][i]='1'
        while q:
            q_pop=q.popleft()
            I=q_pop[0]
            J=q_pop[1]
            if I==n-1:
                chk=0
                break
            for j in x:
                if 0<=I+j[0]<n and 0<=J+j[1]<m and visit[I+j[0]][J+j[1]]=='0':
                    q.append([I+j[0], J+j[1]])
                    visit[I+j[0]][J+j[1]]='1'
if chk: print('NO')
else: print("YES")

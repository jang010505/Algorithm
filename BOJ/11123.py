from collections import deque
for _ in range(int(input())):
    n, m=map(int, input().split())
    d=[]
    for i in range(n):
        d.append(list(input()))
    cnt=0
    for i in range(n):
        for j in range(m):
            if d[i][j]=='#':
                q=deque()
                q.append([i, j])
                d[i][j]='.'
                cnt+=1
                while q:
                    q_pop=q.popleft()
                    I=q_pop[0]
                    J=q_pop[1]
                    if I-1>=0 and d[I-1][J]=='#':
                        q.append([I-1, J])
                        d[I-1][J]='.'
                    if J-1>=0 and d[I][J-1]=='#':
                        q.append([I, J-1])
                        d[I][J-1]='.'
                    if I+1<n and d[I+1][J]=='#':
                        q.append([I+1, J])
                        d[I+1][J]='.'
                    if J+1<m and d[I][J+1]=='#':
                        q.append([I, J+1])
                        d[I][J+1]='.'
    print(cnt)

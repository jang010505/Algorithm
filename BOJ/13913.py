from collections import deque
n, k=map(int, input().split())
visit=[[0, -1] for i in range(100002)]
q=deque()
q.append(n)
visit[n][0]=1
while len(q)!=0:
    now=q.popleft()
    if now==k: break
    if 2*now<=100000 and visit[2*now][0]==0:
        q.append(2*now)
        visit[2*now][0]=1+visit[now][0]
        visit[now*2][1]=now
    if now+1<=100000 and visit[now+1][0]==0:
        q.append(now+1)
        visit[now+1][0]=1+visit[now][0]
        visit[now+1][1]=now
    if now-1>=0 and visit[now-1][0]==0:
        q.append(now-1)
        visit[now-1][0]=1+visit[now][0]
        visit[now-1][1]=now
print(visit[k][0]-1)
que=deque()
que.append(k)
while 1:
    if visit[k][1]!=-1:
        que.appendleft(visit[k][1])
        k=visit[k][1]
    else:
        break
for i in que:
    print(i, end=' ')

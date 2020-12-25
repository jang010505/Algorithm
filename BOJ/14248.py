from collections import deque
n=int(input())
visit=[0]*n
d=list(map(int, input().split()))
s=int(input())
visit[s-1]=1
q=deque()
q.append(s-1)
while q:
    now=q.popleft()
    if 0<=now-d[now] and visit[now-d[now]]==0:
        q.append(now-d[now])
        visit[now-d[now]]=1
    if n>now+d[now] and visit[now+d[now]]==0:
        q.append(now+d[now])
        visit[now+d[now]]=1
print(visit.count(1))

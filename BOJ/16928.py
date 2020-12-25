from collections import deque
n, m=map(int, input().split())
x=[0]*101
for i in range(n+m):
    a, b=map(int, input().split())
    x[a]=b
visit=[-1]*101
q=deque()
q.append(1)
visit[1]=0
while q:
    now=q.popleft()
    if now==100:
        break
    for i in range(1, 7):
        now_=now+i
        if now_>100: continue
        if x[now_]!=0:
            now_=x[now_]
        if visit[now_]==-1:
            visit[now_]=visit[now]+1
            q.append(now_)
print(visit[100])

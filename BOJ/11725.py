from collections import deque
n=int(input())
d=[[] for i in range(n)]
for i in range(n-1):
    a, b=map(int, input().split())
    d[a-1].append(b-1)
    d[b-1].append(a-1)
visit=[0]*n
q=deque()
for i in d[0]:
    visit[i]=1
    q.append(i)
while q:
    now=q.popleft()
    for i in d[now]:
        if visit[i]==0:
            q.append(i)
            visit[i]=now+1
for i in range(1, n):
    print(visit[i])

from collections import deque
for _ in range(int(input())):
    a, b=map(int, input().split())
    visit=[0]*10000
    q=deque()
    q.append([a, ""])
    visit[a]=1
    while q:
        q_pop=q.popleft()
        now=q_pop[0]
        string=q_pop[1]
        if now==b:
            break
        d=(2*now)%10000
        if visit[d]==0:
            q.append([d, string+'D'])
            visit[d]=1
        if now==0: s=9999
        else: s=now-1
        if visit[s]==0:
            q.append([s, string+'S'])
            visit[s]=1
        l=(now//1000)+(now%1000)*10
        if visit[l]==0:
            q.append([l, string+'L'])
            visit[l]=1
        r=(now%10)*1000+now//10
        if visit[r]==0:
            q.append([r, string+'R'])
            visit[r]=1
    print(string)

from collections import deque
def make(num):
    num*=2
    if num>99999:
        return -1
    num-=10**(len(str(num))-1)
    return num
n, t, taget=map(int, input().split())
visit=[0]*100000
dq=deque()
dq.append((n, 0))
visit[n]=1
chk=False
while dq:
    now, cost=dq.popleft()
    if cost>t:
        continue
    if now==taget:
        chk=True
        break
    if now+1<=99999 and visit[now+1]==0:
        visit[now+1]=1+visit[now]
        dq.append((now+1, cost+1))
    num=make(now)
    if 0<=num<=99999 and visit[num]==0:
        visit[num]=visit[now]+1
        dq.append((num, cost+1))
if chk:
    print(visit[taget]-1)
else:
    print("ANG")

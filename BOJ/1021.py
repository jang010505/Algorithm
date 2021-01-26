from collections import deque
n, m=map(int, input().split())
element=list(map(int, input().split()))
dq=deque()
for i in range(1, n+1):
    dq.append(i)
dq_len=n
count=0
answer=0
while count!=m:
    index=dq.index(element[count])
    if dq_len/2<index:
        while dq[0]!=element[count]:
            dq.appendleft(dq.pop())
            answer+=1
        dq.popleft()
    else:
        while dq[0]!=element[count]:
            dq.append(dq.popleft())
            answer+=1
        dq.popleft()
    count+=1
    dq_len-=1
print(answer)

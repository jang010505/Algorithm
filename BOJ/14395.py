from collections import deque
s, t=map(int, input().split())
visit=set()
visit.add(s)
q=deque()
q.append((s, ""))
if s==t:
    print(0)
else:
    result=-1
    while q:
        x, string=q.popleft()
        if x==t:
            result=string
            break
        nx=x*x
        if 0<=nx<=1000000000 and nx not in visit:
            q.append((nx, string+"*"))
            visit.add(nx)
        nx=x+x
        if 0<=nx<=1000000000 and nx not in visit:
            q.append((nx, string+"+"))
            visit.add(nx)
        nx=x//x
        if 0<=nx<=1000000000 and nx not in visit:
            q.append((nx, string+"/"))
            visit.add(nx)
    print(result)

from collections import Counter
t=int(input())
for _ in range(t):
    n=int(input())
    x=[]
    for i in range(n):
        name, kind=input().split()
        x.append(kind)
    res=1
    ans=Counter(x)
    for i in ans:
        res*=ans[i]+1
    print(res-1)

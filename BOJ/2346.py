n=int(input())
info=list(map(int, input().split()))
answer=[i for i in range(1, n+1)]
now=0
tmp=info.pop(now)
print(answer.pop(now), end=' ')
while info:
    if tmp<0:
        now=(now+tmp)%len(info)
    else:
        now=(now+tmp-1)%len(info)
    tmp=info.pop(now)
    print(answer.pop(now), end=' ')
    
    

from collections import deque
n=int(input())
for i in range(n):
    s=input()
    l=int(input())
    q=deque(eval(input()))
    Reversed=False
    for j in s:
        if j=='R': Reversed=not Reversed
        else:
            if l<1:
                print('error')
                break
            if Reversed: q.pop()
            else: q.popleft()
            l-=1
    else:
        if Reversed: q.reverse()
        print(str(list(q)).replace(' ', ''))

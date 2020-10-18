n=int(input())
for i in range(n):
    a, b=map(int, input().split())
    res=1
    for j in range(b-a+1, b+1):
        res*=j
    for j in range(1, a+1):
        res//=j
    print(res)

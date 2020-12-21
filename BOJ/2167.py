n, m=map(int, input().split())
d=[]
for i in range(n):
    d.append(list(map(int, input().split())))
x=int(input())
for i in range(x):
    x1, y1, x2, y2=map(int, input().split())
    res=0
    for j in range(x1-1, x2):
        for k in range(y1-1, y2):
            res+=d[j][k]
    print(res)

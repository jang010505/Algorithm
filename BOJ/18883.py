n, m=map(int, input().split())
count=0
for i in range(n):
    for j in range(m):
        count+=1
        if j!=m-1:
            print(count, end=' ')
        else:
            print(count)

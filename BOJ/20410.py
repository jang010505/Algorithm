m, s, x1, x2=map(int, input().split())
chk=0
for i in range(m):
    for j in range(m):
        if x1==(i*s+j)%m and x2==(i*x1+j)%m:
            print(i, j)
            chk=1
            break
    if chk:
        break

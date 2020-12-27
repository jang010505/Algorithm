n, t=map(int, input().split())
x, y, time=0, 0, 0
r=1
h=1
for i in range(n):
    T, A=input().split()
    T=int(T)
    time=T-time
    if h:
        x+=time*r
    else:
        y+=time*r
    time=T
    if A=="right":
        if h==1 and r==1:
            h, r=0, -1
        elif h==0 and r==1:
            h, r=1, 1
        elif h==1 and r==-1:
            h, r=0, 1
        elif h==0 and r==-1:
            h, r=1, -1
    else:
        if h==1 and r==1:
            h, r=0, 1
        elif h==0 and r==1:
            h, r=1, -1
        elif h==1 and r==-1:
            h, r=0, -1
        elif h==0 and r==-1:
            h, r=1, 1
if time!=t:
    time=t-time
    if h:
        x+=time*r
    else:
        y+=time*r
print(x, y)

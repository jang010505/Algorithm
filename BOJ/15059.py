x1, x2, x3=map(int, input().split())
y1, y2, y3=map(int, input().split())
res=0
if x1<y1: res+=y1-x1
if x2<y2: res+=y2-x2
if x3<y3: res+=y3-x3
print(res)

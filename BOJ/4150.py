x=int(input())
d=[]
d.append(1)
d.append(1)
for i in range(2, x):
    d.append(d[i-1]+d[i-2])
print(d[x-1])

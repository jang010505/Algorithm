n=int(input())
d=[0,1,1]
for i in range(3, 117):
    d.append(d[i-1]+d[i-3])
print(d[n])

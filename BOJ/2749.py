n=int(input())
d=[0,1,1]
for i in range(3, 1500010):
    d.append((d[i-1]+d[i-2])%1000000)
print(d[n%1500000])

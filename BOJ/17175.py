n=int(input())
d=[1,1]
for i in range(2, 100):
    d.append((1+d[i-1]+d[i-2])%1000000007)
print(d[n])

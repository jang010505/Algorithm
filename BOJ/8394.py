x=int(input())
d=[1, 1, 2]
for i in range(3, 1500010):
    d.append((d[i-1]+d[i-2])%10)
print(d[x%1500000])

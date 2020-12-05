a=[]
a.append(0)
a.append(1)
for i in range(2, 1000001):
    a.append((a[i-1]+a[i-2])%1000000007)
print(a[int(input())])

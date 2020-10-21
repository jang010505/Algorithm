x=input()
y=input()
res1, res2=0, 0
for i in range(len(x)):
    if x[i]=='1': res1+=2**(len(x)-i-1)
for i in range(len(y)):
    if y[i]=='1': res2+=2**(len(y)-i-1)
print(bin(res1*res2) [2:])

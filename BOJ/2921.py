x=int(input())
res, a, b=0, 3, 6
for i in range(x):
    res+=a
    a+=b
    b+=3
print(res)

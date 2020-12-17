n = int(input())
res1=1
res2=1
for i in range(n):
    res2+=3
    res1+=res2
print(res1%45678)

def isPrime(x):
    i=2
    while i*i<=x:
        if x%i==0:
            return 0
        i+=1
    return 1
n=int(input())
line=[1, 3, 7, 9]
stack=[7, 5, 3, 2]
start=pow(10, n-1)
end=pow(10, n)
answer=[]
while stack:
    now=stack.pop()
    if start<=now<end:
        if isPrime(now):
            answer.append(now)
        continue
    for v in line:
        if isPrime(now*10+v):
            stack.append(now*10+v)
answer.sort()
print('\n'.join(map(str, answer)))

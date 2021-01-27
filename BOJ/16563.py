def f(N):
    while N>1:
        answer.append(prime[N])
        N//=prime[N]
prime=[i for i in range(5000001)]
i=1
prime[0]=-1
prime[1]=-1
while i*i<=5000000:
    i+=1
    if prime[i]!=i:
        continue
    j=i*i
    while j<=5000000:
        if prime[j]==j:
            prime[j]=i
        j+=i
n=int(input())
info=list(map(int, input().split()))
for i in range(n):
    answer=list()
    f(info[i])
    print(' '.join(map(str, answer)))

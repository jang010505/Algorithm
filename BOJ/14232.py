prime=[0]*(1000001)
i=1
prime[0]=1
prime[1]=1
while i*i<=1000000:
    i+=1
    if prime[i]==1:
        continue
    j=i
    while i*j<=1000000:
        prime[i*j]=1
        j+=1
n=int(input())
count=0
answer=list()
for i in range(2, 1000001):
    if prime[i]==0:
        while n%i==0:
            count+=1
            n//=i
            answer.append(i)
        if n==1:
            break
if n!=1:
    count+=1
    answer.append(n)
print(count)
for i in range(count):
    print(answer[i], end=' ')

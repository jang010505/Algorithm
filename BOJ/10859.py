def isprime(num):
    i=2
    if num==1:
        return False
    while i*i<=num:
        if num%i==0:
            return False
        i+=1
    return True
n=input()
reverse=0
for i in range(len(n)-1, -1, -1):
    if n[i]=='3' or n[i]=='4' or n[i]=='7':
        print("no")
        exit()
    elif n[i]=='6':
        reverse*=10
        reverse+=9
    elif n[i]=='9':
        reverse*=10
        reverse+=6
    else:
        reverse*=10
        reverse+=int(n[i])
n=int(n)
if isprime(n) and isprime(reverse):
    print("yes")
else:
    print("no")

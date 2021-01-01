def divide(x, y, z):
    if z==0:
        return
    for i in range(x+z, y-z):
        dp[i]=1
    divide(x, x+z, z//3)
    divide(y-z, y, z//3)
while True:
    try:
        n=int(input())
        N=3**n
        dp=[0]*(N+1)
        divide(1, N+1, N//3)
        for i in range(1, N+1):
            if dp[i]:
                print(" ", end='')
            else:
                print("-", end='')
        print()
    except EOFError:
        break

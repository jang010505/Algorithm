def w(a, b, c):
    if dp[a][b][c]!=0:
        return dp[a][b][c]
    if a<=0 or b<=0 or c<=0:
        return 1
    if a>20 or b>20 or c>20:
        dp[a][b][c]=w(20, 20, 20)
        return dp[a][b][c]
    if a<b<c:
        dp[a][b][c]=w(a, b, c-1)+w(a, b-1, c-1)-w(a, b-1, c)
        return dp[a][b][c]
    else:
        dp[a][b][c]=w(a-1, b, c)+w(a-1, b-1, c)+w(a-1, b, c-1)-w(a-1, b-1, c-1)
        return dp[a][b][c]
a, b, c=map(int, input().split())
dp=[]
for i in range(21):
    dp.append([[0]*21 for j in range(21)])
while a!=-1 or b!=-1 or c!=-1:
    if a<=0 or b<=0 or c<=0:
        print("w(%d, %d, %d) = %d"%(a, b, c, w(0, 0, 0)))
    elif a>20 or b>20 or c>20:
        print("w(%d, %d, %d) = %d"%(a, b, c, w(20, 20, 20)))
    else:
        print("w(%d, %d, %d) = %d"%(a, b, c, w(a, b, c)))
    a, b, c=map(int, input().split())

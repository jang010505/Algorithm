def printMatrix(m):
   for i in range(len(m)):
      for j in range(len(m[i])):
         print(m[i][j],end=' ')
      print()
def addMatrix(m,n):
   for i in range(len(m)):
      for j in range(len(m[i])):
         print(m[i][j]+n[i][j],end=' ')
      print()
n, m=map(int, input().split())
x, y=[], []
for i in range(n):
    x.append(list(map(int, input().split())))
for i in range(n):
    y.append(list(map(int, input().split())))
addMatrix(x, y)

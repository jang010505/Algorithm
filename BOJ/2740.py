def printMatrix(m):
   for i in range(len(m)):
      for j in range(len(m[i])):
         print(m[i][j],end=' ')
      print()
def multiplyMatrix(A,B):
   x,y,z=len(A),len(B),len(B[0])
   t=[]    
   for i in range(x):
      t.append([])
      for j in range(z):
         t[i].append(0)
      for j in range(y):
         for k in range(z):
            t[i][k]+=A[i][j]*B[j][k]
   return t
n, m=map(int, input().split())
A,B=[],[]
for i in range(n):
   A.append(list(map(int, input().split())))
m, k=map(int, input().split())
for i in range(m):
   B.append(list(map(int, input().split())))
printMatrix(multiplyMatrix(A,B))

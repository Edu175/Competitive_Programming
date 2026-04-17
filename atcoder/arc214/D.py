from math import comb
n=int(input())
a=[[0]*n]
print(*a[0])
for i in range(1,n):
	a+=[[0]*n]
	for j in range(n-2,-1,-1):
		a[i][j]=comb(i+j-1,j)+a[i-1][j+1]
	print(*a[i])
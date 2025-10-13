from fractions import Fraction
n=int(input())
fra=Fraction
a=list(map(int,input().strip().split()))
p=[fra(0) for i in range(105)]
res=fra(0)
for i in range(n-1,-1,-1):
	# for j in range(a[i]):
	# 	for k in range(j):
	# 		res+=p[k]/a[i]
	for k in range(a[i]):
		res+=(a[i]-k-1) * p[k]/a[i]
	for j in range(a[i]):
		p[j]+=fra(1,a[i])
from decimal import Decimal, getcontext
getcontext().prec = 40
ans=Decimal(res.numerator)/Decimal(res.denominator)
# print(ans)
ans=round(ans,6)
print(f"{ans:.{6}f}")

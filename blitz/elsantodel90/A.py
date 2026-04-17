A=int(input())
from fractions import fraction as fr

for b in range(2,A):
	sum=0
	a=A
	cant=0
	while a:
		sum+=a%b
		a/=b
		cant+=1
	
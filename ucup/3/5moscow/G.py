from math import exp
LG=11
N=(24-LG+1)//2
K=1<<LG

a=[0 for i in range(N)]

coef=1
for n in range(N):
	if n: coef*=K*n
	a[n]=1/coef

print(24)
for i in range(N-1,-1,-1):
	if i<N-1: print("$0 = $0 * $1")
	print("$0 = $0 +",a[i])
for i in range(LG):
	print("$0 = $0 * $0")

def test():
	L=-2*10**6
	R=-L
	D=10**5
	mxerr=1e-9
	mx=0
	for n in range(L,R+1):
		x=n/D
		y1=exp(x)
		y2=0
		for i in range(N-1,-1,-1):
			y2=y2*x+a[i]
		# print(y2)
		for i in range(LG): y2=y2*y2
		err=abs(y1-y2)/y1
		# print(x,":",y1,y2,':',err)
		mx=max(mx,err)
	print('max error:',mx)
	print('allowed error:',mxerr)
	print(mx<=mxerr)

# test()
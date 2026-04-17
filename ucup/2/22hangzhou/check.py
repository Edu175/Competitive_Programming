from os import system as sys
it=10000
for _ in range(it):
	sys('./c<pre>in')
	sys('./a<in>o')
	sys('./b<in>o2')
	x=open('o','r').read().strip().split()
	y=open('o2','r').read().strip().split()
	x=list(map(float,x))
	y=list(map(float,y))
	if len(x) != len(y):
		print("FAILED!!!")
		print("lengths dont match")
		exit(0)
	for i in range(len(x)):
		a=x[i]
		b=y[i]
		errN=abs(a-b)
		errD=max(1,abs(b))
		if errN *2 > errD:
			print("FAILED!!!")
			print("expected",b,'found',a)
			print("error",errN/errD)
			print(i,'-th token')
			exit(0)
	print('ok',_+1)

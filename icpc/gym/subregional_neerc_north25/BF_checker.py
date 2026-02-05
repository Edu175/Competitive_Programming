from os import system as sys

it=10000

for _ in range(it):
	sys("./c<pre>in")	#./c = generator
	sys("./a<in>o")		#./a = solution
	sys("./b<in>o2")	#./b = brute force
	x=open("o","r").read().strip().split()
	y=open("o2","r").read().strip().split()
	if len(x)!=len(y):
		print('Error, lengths don\'t match')
		exit(0)
	for i in range(len(y)):
		a=int(x[i])
		b=int(y[i])
		ratio=max(a/b,b/a)
		if not ratio<=1.5:
			print('FAILED!!!!')
			print('expected',b,'found',a)
			print('ratio =',ratio)
			exit(0)
	print("ok",_+1)

from os import system as sys
it=10000
for _ in range(it):
	sys('./c<pre>in')
	sys('./a<in>o')
	x=open('o','r').read().strip().split()
	if x[0]=='WA':
		print("FAILED!!!")
		exit(0)
	print("ok",_+1)
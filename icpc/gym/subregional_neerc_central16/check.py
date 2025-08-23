from os import system

it=1000
for _ in range(it):
	system('./c<pre>in')
	system('./a<in>o')
	system('./b<in>o2')
	x=open('o','r').read().strip().split()
	y=open('o2','r').read().strip().split()
	if(x[0]!=y[0]):
		print("failed!!!")
		exit(0)
	print("ok",_+1)
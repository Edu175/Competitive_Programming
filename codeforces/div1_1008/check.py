from os import system
it=10000
for _ in range(it):
	system('./c<pre>in')
	system('./a<in>o')
	x=open('o','r').read().strip().split()
	if not len(x):
		print('FAILED!!')
		exit(0)
	print('ok',_+1)
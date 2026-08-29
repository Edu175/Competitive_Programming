from os import system as sys
it=10000
for _ in range(it):
	sys('./c>in')
	sys('./a<in>o')
	x=open('o','r').read().strip().split()
	if x[-1]!='AC':
		print('FAILED!!!')
		exit(0)
	print('ok',_+1)
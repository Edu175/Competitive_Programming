from os import system as sys
it=10000
for _ in range(it):
	sys('./c<pre>in')
	sys('./a<in>o')
	sys('./b<in>o2')
	x=open('o','r').read().strip().split()
	y=open('o2','r').read().strip().split()
	if x!=y:
		# x=x[-1]
		# for i in range(1,len(y)+1):
		# 	z=y[len(y)-i]
		# 	if(z<"0" or )
		print('FAILED!!!')
		exit(0)
	print('ok',_+1)
from os import system
it=10000
for _ in range(it):
	system('./c<pre>in')
	system('./a<in>o')
	x=open('o','r').read().strip().split()
	if(x[0]=="No"):
		print("ok",_+1)
		continue
	y=open('in','r').read().strip().split()
	res=y[0]+'\n'
	for i in range(1,len(y)):
		res+=y[i]
		if(i&1):
			res+=' '
		else:
		 	res+='\n'
	res+='\n'
	for i in x:
		res+=i+' '
	ar=open('res','w')
	ar.write(res)
	ar.close()
	system('./b<res>v')
	v=open('v','r').read().strip().split()
	if(v[0]!='YES'):
		print('FAILED!!!')
		exit(0)
	print('ok',_+1)

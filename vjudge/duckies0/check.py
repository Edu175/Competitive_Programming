from os import system
it=100
for _ in range(it):
	system("./c<pre>in")
	system("./a<in>o")
	system("./b<in>o2")
	x=open("o","r").read().strip().split()
	y=open("o2","r").read().strip().split()
	if(x[0]!=y[0]):
		print("FAILED!!!")
		print("expected:",y[0],"found:",x[0])
		exit(0)
	print("ok",_+1)

from os import system
it=10000
for i in range(it):
	system("./c<pre>in")
	system("./a<in>o")
	system("./d<in>o2")
	x=open("o","r").read().strip().split()
	y=open("o2","r").read().strip().split()
	if(x!=y):
		print("FAILED!!!",i+1)
		exit(0)
	print("ok",i+1)

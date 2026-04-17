from os import system
it=10000
for i in range(it):
	system("./c<pre>in")
	system("./a<in>o")
	x=open("o","r").read().strip().split()
	if(x[0]!="Accepted:"):
		print("FAILED!!!",i+1)
		exit(0)
	print("ok",i+1)
	

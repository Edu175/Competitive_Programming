from os import system as sys 
it=10000
for _ in range(it):
	sys("./c<pre>in")
	sys("./a<in>o")
	# sys("./b<in>o2")
	sys('python3 checker.py>veredict')
	x=open("veredict","r").read().strip().split()
	if x[0]!='AC':
		print("FAILED!!!")
		exit(0)
	print("ok",_+1)
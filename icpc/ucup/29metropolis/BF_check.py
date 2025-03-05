from os import system as sys

n=5
it=1<<5
for _ in range(it):
	pre=open('pre','w')
	pre.write(str(n)+"\n"+str(_))
	sys("./c<pre>in")	#./c = generator
	sys("./a<in>o")		#./a = solution
	sys("./b<in>o2")	#./b = brute force
	x=open("o","r").read().strip().split()
	y=open("o2","r").read().strip().split()
	
	if x!=y:
		print("FAILED!!!!!")
		print("expected",y,"found",x)
		exit(0)
	
	print("ok",_+1)

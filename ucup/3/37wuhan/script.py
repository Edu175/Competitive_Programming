from os import system
for k in range(21):
	x=open('in','w')
	x.write(str(k))
	x.close()
	system('python3 h.py<in>o')
	a=open('o','r').read().strip().split()
	print('(',a[0],',',a[1],'),')
def ppc(x):
	return bin(x).count('1');
t=int(input())
for _ in range(t):
	n=int(input())
	d=1
	if(ppc(n)&1):
		print("second")
	else:
		print("first")
		d=0
	while(1):
		if(d):
			p,q=map(int,input().strip().split())
			if not p: break
			if p==-1: exit(0)
			if ppc(p)%2==0: n=p
			else: n=q
		d=1
		x=1<<(n.bit_length()-1)
		print(x,x^n)

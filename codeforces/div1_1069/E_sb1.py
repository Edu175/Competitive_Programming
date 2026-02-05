# from sympy.ntheory.modular import crt
def combine(a,b,m,n): # n,m coprime
	k=(b-a)*pow(m,-1,n)
	x=(m*k+a)%(m*n)
	return (x,m*n)
def crt(ms,rs): # asumo pairwise coprime
	a=0; m=1
	for i in range(len(ms)):
		b=rs[i]; n=ms[i]
		a,m=combine(a,b,m,n)
	return a,m
def ask(b):
	print('?',b)
	ret=int(input())
	if ret==-2: exit(0)
	return ret
def answer(x):
	print('!',x)
	r=int(input())
	if not r: exit(0)

def getr(m):
	r=ask(m+1)
	if r!=-1: r%=m
	return r

def do_crt(_ms,got):
	ms=[m for m in _ms]
	rs=[getr(ms[0]),getr(ms[1]),got]
	(sol,mod)=crt(ms,rs)
	# print(ms,rs)
	# print('=',sol,mod)
	answer(sol)

big=[1587401,1587402,1587403]
med=[117,118,119]
small=[5,6,7]

t,_k,_c=list(map(int,input().strip().split()))
for __ in range(t):
	gotm=getr(med[-1])
	if gotm!=-1:
		gotb=getr(big[-1])
		if gotb !=-1: do_crt(big,gotb)
		else: do_crt(med,gotm)
	else:
		gots=getr(small[-1])
		if gots !=-1:
			do_crt(small,gots)
			continue
		# in range [1..7]
		got=ask(4)
		if got!=-1: answer(got+3) # only place using 3 queries
		else: answer(max(ask(2)+1,1))
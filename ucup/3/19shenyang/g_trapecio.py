from fractions import Fraction as fr

def ask(x):
	x = fr(x)
	print('?', x.numerator, x.denominator)
	r, s = list(map(int, input().strip().split()))
	return fr(r, s)

t = int(input())
for _ in range(t):
	n = int(input())
	xs = set()
	for __ in range(n):
		x, y = list(map(int, input().strip().split()))
		xs.add(x)

	xs = list(xs)
	xs.sort()
	m = len(xs)
	mid=[0 for i in range(m-1)]
	
	if m==n:
		lat=[]
		for i in range(m):
			lat.append(fr(0) if not i or i==m-1 else ask(xs[i]))
		for i in range(m-1):
			mid[i]=fr(lat[i]+lat[i+1],2)
	else:
		for i in range(m-1):
			mid[i]=ask(fr(xs[i]+xs[i+1],2))
	res=0
	for i in range(m-1):
		res+= (xs[i+1]-xs[i])*mid[i] # regla del trapecio
	print('!',res.numerator,res.denominator)
    
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
	hist = {}

	for __ in range(n):
		x, y = list(map(int, input().strip().split()))
		#print(x, y)
		#print(type(x))
		if not x in hist: hist[x] = 1
		else: hist[x] += 1
		xs.add(x)

	xs = list(xs)
	xs.sort()
	# print(xs)
	m = len(xs)
	l = [0 for i in range(m)]
	r = [0 for i in range(m)]
	ok = [0 for i in range(m)]

	def borde(i, arr):
		ok[i] = 1
		x = xs[i]
		if hist[x] == 1: return
		arr[i] = ask(x)

	borde(0,r)
	borde(m-1,l)

	for i in range(1, m - 1):
		x = xs[i]
		if hist[x] == 1:
			l[i] = r[i] = ask(x)
			ok[i] = 1
		else:
			l[i] = ask(x - fr(1, 3))
			r[i] = ask(x + fr(1, 3))

	def get(a, b, c):
		d = fr(1, 3)
		r = fr(b - a)
		ans = b + fr(d, c) * r
		# (original code did not explicitly return ans)
		return ans

	for i in range(m):
		x = xs[i]
		if not ok[i]:
			dl = x - xs[i - 1]
			dr = xs[i + 1] - x
			l[i] = get(r[i - 1], l[i], dl - fr(1, 3))
			if ok[i + 1]:
				r[i] = get(l[i + 1], r[i], dr - fr(1, 3))
			else:
				r[i] = get(l[i + 1], r[i], dr - fr(2, 3))
		#print(i, x, ':', l[i], r[i])

	res = 0

	def area(b0, b1,h):
		return h*fr(b0 + b1, 2)

	for i in range(m - 1):
		res += area(r[i], l[i + 1],xs[i+1]-xs[i])

	print('!', res.numerator, res.denominator)
    
def f(n):
	a=[]
	while(n):
		a.append(n%9)
		n//=9
	return a
def af(a):
	x=a[0]
	for i in range(1,len(x)):
		x=x*9+a[i]
	return x
digits=['la','le','lon','sha','she','shon','ta','te','ton']
def cv(a):
	for i in range(digits):
		if a==digits[i]:
			return i
def g(s):
	a=[]
	for i in range(s):
		
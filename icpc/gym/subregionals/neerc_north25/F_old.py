from random import *
import sys


sys.set_int_max_str_digits(10**10)

def solve(s, c):

	n = len(s)

	l = 0
	r = n

	while (l + 1 < r):
		m = (l + r) // 2
		a = int(s[:m])
		b = int(s[m:])
		a2 = b * c
		if (a2 < a):
			r = m
		else:
			l = m
		
	m = (l + r) // 2

	a = int(s[:m])
	b = int(s[m:])
	a2 = b * c
	assert (a2 == a and s[m] != '0')
	
	return a, b

# for _ in range(100000):
# 	print(_)
# 	b = randint(1, 10**(10**5))
# 	c = randint(1, 10**(10**5))
# 	a = b * c
	
# 	a = int(str(a))
	
# 	solve(str(a) + str(b), c)

s, c = input().split()

# co = '1' + '0' * 10**3
# bo = '1' + '0' * 10**3
# ao = str(int(co) * int(bo))
# s = ao + bo
# c = co


c = int(c)

a, b = solve(s, c)

print(a, b)

	


import itertools
n=10
a=[]
for i in range(10):
	a.append(input())
b=a[2:]
list(itertools.permutations(b))

import sys
sys.setrecursionlimit(10**5+5)
a=[['for','1']]
n=int(input())
for i in range(n):
	a.append(input().strip().split())
a.append(['end'])
# print(a)
p=0
def f():
	global p
	# print('for')
	assert(a[p][0]=='for')
	mul=int(a[p][1])
	p+=1
	res=0
	while(1):
		while a[p][0]=='add':
			res+=1
			p+=1
		if a[p][0]=='end':
			res*=mul
			p+=1
			if(res>=(1<<32)):
				print("OVERFLOW!!!")
				exit(0)
			return res
		assert a[p][0]=='for'
		res+=f()
		# if(res>=(1<<32)):
		# 	print("OVERFLOW!!!")
		# 	exit(0)
	assert(0)
print(f())
	
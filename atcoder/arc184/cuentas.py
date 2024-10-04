n=36
a=[0 for i in range(n)]
def go(i,a):
	a[i]=1
	a[2*i%n]=1
	a[3*i%n]=1 

for i in range(n):
	if i%6==1 or i%6==5:
		go(i,a)

go(9,a)
def show():
	for i in range(n):
		if(not a[i]):
			print(i)

# a=[0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1]
print(a)
lib=[i for i in range(n) if i%2==0]
print(lib)
c=[[] for i in range(len(lib)+1)]
for mk in range(1<<len(lib)):
	b=[i for i in a]
	for i in range(len(lib)):
		if mk>>i&1: go(lib[i],b)
	flag=1
	for i in range(n): flag&=b[i]
	if flag: c[bin(mk).count('1')].append(mk)

for i in range(len(lib)):
	print(i,':',end=' ')
	for mk in c[i]:
		for j in range(n):
			if mk>>j&1: print(lib[j],end=',')
		print('',end=' ')
	print('')
	
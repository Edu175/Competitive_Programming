from fractions import Fraction as fr
def ask(a):
	s=""
	for i in a: s+=str(i)+" "
	print(s)
	ret=int(input())
	return ret

def solve(a):
	n=len(a)
	m=len(a[0])
	vis=[0]*3
	# print("solve")
	# for i in a:
	# 	print(i)
	for i in range(n):
		for j in range(m): a[i][j]=fr(a[i][j])
	ans=[fr(0)]*3
	for i in range(3):
		p=-1
		for j in range(m):
			if a[i][j]!=fr(0):
				p=j
				break
		# print(i,p,':',a[i])
		assert not vis[p]
		vis[p]=1
		d=fr(1,a[i][p])
		for j in range(m): a[i][j]*=d
		assert a[i][p]==fr(1,1)
		for i2 in range(n):
			if i!=i2:
				mu=a[i2][p]
				for j in range(m):
					a[i2][j]-=a[i][j]*mu
				assert a[i2][p]==fr(0)
	assert vis[0] and vis[1] and vis[2]
	for i in range(3):
		p=-1
		for j in range(m):
			if a[i][j]!=fr(0):
				p=j
				break
		ans[p]=a[i][3]
	return ans

a=[
	[1,0,0],
	[0,1,0],
	[0,0,1],
	[1,1,1],
	[1,2,3],
   ]

for i in range(len(a)):
	r=ask(a[i])
	a[i].append(r)

all=[]

for i in range(len(a)):
	for i2 in range(i+1,len(a)):
		b=[]
		for j in range(len(a)):
			if j==i or j==i2: continue
			# print(i,i2,j,'pinga')
			row=[]
			for e in a[j]: row.append(e)
			b.append(row)
		got=solve(b)
		# print(got)
		all.append(got)

for ans in all:
	c=0
	for i in all: c+=ans==i
	if c>=2:
		res=[]
		for i in ans:
			assert i.denominator==1
			res.append(i.numerator)
		s=""
		for i in res: s+=str(i)+" "
		print(s)
		exit(0)
assert(0)



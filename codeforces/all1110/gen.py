from random import randint
def aggr(a,b):
	mx=max(len(a),len(b))
	c=[[] for i in range(mx)]
	for i in range(len(c)):
		if i<len(a): c[i]+=a[i]
		if i<len(b): c[i]+=b[i]
	return c
def offs_lev(a,c):
	for i in range(len(a)):
		for j in range(len(a[i])):
			a[i][j]+=c
	return a
def offs_ed(ed,c):
	ret=[]
	for (u,v) in ed: ret.append((u+c,v+c))
	return ret
def f(k):
	if k==-0:
		return [],[[0]]
	n=0
	ed=[]
	lev=[]
	vec=[]
	for i in range(k-1,-1,-1):
		cur_ed,cur_lev=f(i)
		cur_ed=offs_ed(cur_ed,n)
		cur_lev=offs_lev(cur_lev,n)
		n+=len(cur_ed)+1
		ed+=cur_ed
		lev=aggr(lev,cur_lev)
		vec.append(cur_lev[-1][0])
	for y in vec: ed.append((n,y))
	lev.append([n])
	# print('f',k,ed,lev)
	return ed,lev
def do_test_k(k):
	ed,lev=f(k)
	n=len(ed)+1
	nod=[]
	for a in lev: nod+=a
	# print('nod',nod)
	pos=[0]*n
	for i in range(n): pos[nod[i]]=i
	print(n)
	for (u,v) in ed:
		print(pos[u]+1,pos[v]+1)
	
def do_test(n):
	k=0
	while (1<<k)<n: k+=1
	ed,lev=f(k)
	m=len(ed)+1
	nod=[]
	for a in lev: nod+=a
	
	uf=[i for i in range(n)]
	def find(x):
		if x!=uf[x]: uf[x]=find(uf[x])
		return uf[x]
	def unite(x,y): uf[find(x)]=find(y)
	assert m>=n
	nod=[i for i in nod if i<n]
	ed=[(u,v) for (u,v) in ed if u<n and v<n]
	for (u,v) in ed: unite(u,v)
	while len(ed)<n-1:
		u=randint(0,n-1)
		v=randint(0,n-1)
		if find(u)!=find(v):
			unite(u,v)
			ed.append((u,v))
	# for i in range(n-1):
	# 	if find(i)!=find(n-1):
	# 		ed.append((i,n-1))
	# 		unite(i,n-1)
	# print('nod',nod)
	pos=[0]*n
	for i in range(n): pos[nod[i]]=i
	print(n)
	for (u,v) in ed:
		print(pos[u]+1,pos[v]+1)
print(1)
do_test(1000)
# do_test_k(3)
# do_test_k(9)
	
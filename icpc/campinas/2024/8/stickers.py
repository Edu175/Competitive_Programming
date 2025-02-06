import matplotlib.pyplot as plt
def ones(n):
	n+=1
	res=0
	ni=n
	a=list()
	while(ni):
		a.append(ni%10)
		ni//=10
	#print(a)
	for i in range(len(a)):
		if(i): res+=10**(i-1)*i*a[i]
		if(a[i]>1): res+=10**i
		if(a[i]==1): res+=n%10**i
	return res
#print(ones(12))
#exit(0)
k=int(input())
s=int(input())
e=int(input())
def can(n): return k*n>=ones(n)
a=[];b=[]
for i in range(s,e):
	a.append(ones(i)-k*i)
	b.append(k*i)
plt.plot(a)
#plt.plot(b,'r')
plt.show()
'''
n=1
while(can(n)): n+=1
print(n)
for i in range (1,10**8):
	if(can(i) ^ can(i-1)): print(i)
'''
'''
def search(l,r):
	#print('search',l,r)
	r-=1
	while(l<=r):
		m=(l+r)//2
		if(m*k>=ones(m)): l=m+1
		else: r=m-1
	#print(l)
	return l
l=0;r=10**(10*k+1)
while(1):
	ri=search(l,r)
	if(ri==r): break
	r=ri
print(r)
'''


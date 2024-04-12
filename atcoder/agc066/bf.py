def greedy(a,d):
	r=0
	for i in range(1,len(a)):
		x=0
		if(abs(a[i]-a[i-1]>=d)):
			continue
		if(a[i-1]<a[i]):
			x=a[i-1]+d
		else: 
			x=a[i-1]-d
		r+=abs(x-a[i])
		a[i]=x
	return r
	
def valid(a,d):
	print(greedy(a,d),len(a)/2*d)
		

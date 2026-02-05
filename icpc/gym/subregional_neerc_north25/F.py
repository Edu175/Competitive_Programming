
s,c=list(input().strip().split())
# print(s,c)
d=len(c)
c=int(c)

for m in range(1,len(s)):
	if s[m]=='0': continue
	l=m
	r=len(s)-m
	if abs(l-(r+d))<=4:
		# print(m,'good')
		a=int(s[0:m])
		b=int(s[m:])
		if c*b==a:
			print(a,b)
			exit(0)
assert(0)
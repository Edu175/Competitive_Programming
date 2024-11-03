n=int(input())
s=input()
input()
p=list(map(int,input().strip().split()))
for i in range (0,n):
	x=1
	r=0
	for j in p:
		r+=j*x
		x*=2*i+1
	k=1
	if(s[i]!='H'):
		k=-1
	if(r*k<=0):
		print("pingo")
print("que bien")

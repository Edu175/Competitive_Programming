from sympy import totient
MOD=212345678987654321
P=1777771
cnt=0
x=MOD
while x>1:
	print(x,cnt)
	cnt+=1
	x=totient(x)

K=100
def hsh(x,k):
	for i in range(k):
		x=pow(P,x,MOD)
	return x
r1=28394798
r2=239840438
print(hsh(r1,K))
print(hsh(r2,K))
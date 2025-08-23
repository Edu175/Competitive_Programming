from math import *

t=int(input())
while(t):
	I=input().strip().split()
	for i in range(6):
		I[i]=int(I[i])
	(A,B,C,X,Y,D)=I
	r=A*((D+X-1)//X)
	if D<=X+Y and D>X: r=min(r,A+B*(D-X))
	if D>=X+Y:
		D1=D-(X+Y)
		if(D1<X+Y):
			AUX1=max(0,D1-X)
			r=min(r,A+B*Y+min(C*D1,A+min(A*((AUX1+X-1)//X),B*AUX1)))
		else:
			aux=min(A+B*Y,C*(X+Y))
			
			D2=D1%(X+Y)
			# print(type(D2),type(X),type(0), type(min(0,D2-X)))
			AUX1=max(0,D2-X)
			
			AUX2=min(A*((AUX1+X-1)//X),B*AUX1)
			AUX3=min(C*D2,A+AUX2)
			# print(D2)
			r=min(r,A+B*Y+aux*(D1//(X+Y))+AUX3)
	print(r)
	t-=1
# 5
# 160 27 41 3 12 3
# 160 27 41 3 12 4
# 160 27 41 3 12 99
# 1 999 999 1 99 999
# 999 999 1 1 99 9999999999999999
# 160
# 187
# 3224
# 999
# 10000000000099799

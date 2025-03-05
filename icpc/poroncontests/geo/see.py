from matplotlib.pyplot import *
for _ in range(3):
	n=int(input())
	xs=[]
	ys=[]
	for i in range(n):
		x,y=list(map(float,input().strip().split()))
		xs.append(x)
		ys.append(y)
	xs.append(xs[0])
	ys.append(ys[0])
	plot(xs,ys)
#  independent
# m=int(input())
# for i in range(m):
# 	x,y=list(map(float,input().strip().split()))
# 	plot(x,y,marker='o',label=str(i))
# plot()
axis('equal')
show()
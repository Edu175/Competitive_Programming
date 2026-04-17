from matplotlib.pyplot import *
lin=input().strip().split()
xs=[]
ys=[]
for e in lin:
	x,y=list(map(float,e.split(sep=',')))
	xs.append(x)
	ys.append(y)
xs.append(xs[0])
ys.append(ys[0])
plot(xs,ys)
plot([0.5,0.5],[0,1])
plot([0,1],[0.5,0.5])
show()
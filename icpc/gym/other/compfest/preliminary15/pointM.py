from fractions import Fraction as fr
n=int(input())
p=list(map(int,input().strip().split()))
for i in range(len(p)):
	p[i]=fr(p[i],100)
print(p)
class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __repr__(self):
        return f"Point({self.x}, {self.y})"

    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Point(self.x - other.x, self.y - other.y)

    def __mul__(self, scalar):
        return Point(self.x * scalar, self.y * scalar)

    def __rmul__(self, scalar):
        return self.__mul__(scalar)

    def __truediv__(self, scalar):
        return Point(self.x / scalar, self.y / scalar)
f=[fr(0)]*(n+1)
f[0]=Point(fr(0),fr(1))
for i in range(0,n):
	f[i+1]=(f[i]-Point(fr(1),fr(0))-f[0]*p[i]**(i+1))/(1-p[i])
	for j in range(i):
		f[i+1]-=f[i-j]*p[i]**(j+1)
print(f)
u=f[n]
ans=-u.x/u.y
print(ans)
# assert(f[n+1]==0)

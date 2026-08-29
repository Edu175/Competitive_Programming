class pt(tuple):
    def __sub__(self, other: tuple) -> "pt":
        if len(self) != len(other):
            raise ValueError("Tuples must be of equal length for subtraction")
        # Subtract element-wise using zip
        return pt(a - b for a, b in zip(self, other))
a=pt((9, 2))
b=pt((6, 13))
c=pt((11, 12))
d=pt((2, 6))
def rcw(a):
	(x,y)=a
	return (y,-x)
def rccw(a):
	(x,y)=a
	return (-y,x)
p=b-a -rcw(d-c)
v=rccw(p)
print(v)
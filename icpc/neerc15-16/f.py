from fractions import Fraction as F
import sys
sys.stdin =  open('fygon.in', 'r') 
sys.stdout = open('fygon.out', 'w')
program=""
while 1:
    try: 
        s=input()
    except:
        break
    # for i in s: print(ord(i),end=' ')
    # print(s)
    # if s=='': break
    if s[-1]=='g':
        s=s[:len(s)-3]
        s+='res+=1'
    program+=s+"\n"
# program+="print(res)"
# print(program)

def val(n):
    res=0
    d=dict()
    d['res']=0
    d['n']=n
    exec(program,None,d)
    # print(d)
    # print(res)
    return d['res']
C=7
a=[]
for i in range(C):
    a.append(val(i))

def add(A,B):
    a=list(A)
    b=list(B)
    if len(a)<len(b): a,b=b,a
    n=len(a)
    c=list(a)
    for i in range(len(b)):
        c[i]+=b[i]
    # print('add',A,B,'=',c)
    return c
def mul(a,b):
    c=[0 for i in range(len(a)+len(b)-1)]
    for i in range(len(a)):
        for j in range(len(b)):
            c[i+j]+=a[i]*b[j]
    # print('mul',a,b,'=',c)
    return c
	
def value(a,n):
    res=0
    for i in range(len(a)):
        res+=a[i]*n**i
    return res
res=[F(0)]
for i in range(C):
    t=[F(1)]
    for j in range(C):
        if i!=j:
            m=[F(-j),F(1)]
            t=mul(t,m)
    v=value(t,i)
    m=[F(a[i],v)]
    t=mul(t,m)
    res=add(res,t)
# res=res[:-2]
# print(res)
for i in range(len(res)):
    num=res[i].numerator
    if(num>=0 and i): print('+',end=' ')
    print(num,'/',res[i].denominator,"*n"*i,end=' ')
print('\n')
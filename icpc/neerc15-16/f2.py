from fractions import *
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

def sum(A,B):
    a=list(A)
    b=list(B)
    if len(a)<len(b): a,b=b,a
    n=len(a)
    c=list(a)
    for i in range(len(b)):
        c[i]+=b[i]
    return c
# def esc(a,b): # b es una constante
#     c=[i*b for i in a]
#     return c
# def shift(a,b):
#     c=[0 for i in b]
#     for i in a:
#         c.append(i)
def mul(a,b):
    c=[0 for i in range(len(a)+len(b))-1]
    for i in range(len(a)):
        for j in range(len(b)):
            c[i+j]+=a[i]*b[i]
    return c
res=''
for i in range(C):
    t=''
    for j in range(C):
        if i!=j:
            t+='(n-'+str(j)+') * '
    t=t[:-2]
    n=i
    v=eval(t)
    t+="* "+str(a[i])+"/"+str(abs(v))+' '
    if v<0: res+="- "
    elif i: res+='+ '
    res+=t
# res=res[:-2]
print(res)



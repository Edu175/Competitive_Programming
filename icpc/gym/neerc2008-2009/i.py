import sys

sys.stdin = open('important.in','r')
sys.stdout = open('important.out','w')

n=int(input())
letras=[]
for i in range (n):
    s=input()
    j=0
    while(s[j]<'A'):
        j=j+1
    letras.append(s[j])
print("Yes")
st=""
for i in range (len(letras)):
    st+=("(")
    st+=(letras[i])
    st+=(" | ~")
    st+=(letras[i])
    st+=(")")
    if (i!=len(letras)-1):
        st+=(" & ")
print(st)

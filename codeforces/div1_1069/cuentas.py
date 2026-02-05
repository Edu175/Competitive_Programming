def good(a):
    for i in range(len(a)):
            for j in range(i+1,len(a)):
                    if gcd(a[i],a[j])!=1: return 0
    return 1

def val(a):
    prod=1
    for i in a: prod*=i
    return good(a)*prod

def ask(b):
    if x<b: return -1
    res=0
    xi=x
    while xi:
        res+=xi%b
        xi//=b
    return res
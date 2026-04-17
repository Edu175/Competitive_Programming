n=int(input())
m=998244353
print(((pow(4,n,m)-pow(3,n+1,m)+3*pow(2,n,m)-1)%m+m)%m)
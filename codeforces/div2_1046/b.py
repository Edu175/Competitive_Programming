t=int(input())
for _ in range(t):
    n,k=list(map(int,input().strip().split()))
    a=list(map(int,input().strip().split()))
    m=k+1
    for v in a:
        c=(m-v)*pow(k,-1,m)%m
        v+=c*k
        print(v,end=' ')
    print('\n')
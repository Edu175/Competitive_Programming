#include <bits/stdc++.h>
#define F(a) for(i=a;i<n;++i)
int main(){
	long long n,k,x,a,b,c,i;
	std::cin>>n>>k>>x>>a>>b>>c;
	int l[n]={x},r[n];
	F(1)x=l[i]=(x*a+b)%c;
	F(0)x=r[i]=l[i]|(i%k?x:0);
	x=a=0;
	for(i=n;i--;)x=l[i]|=(i%k?x:0);
	F(k-1)a^=l[i-k+1]|r[i];
	std::cout<<a;
}
#include <bits/stdc++.h>
#define R(n) for(i=n;i--;)
#define p pair<I,I>
using namespace std;
#define I int
I u['   '],n,m,k,x,y,i;
p e['   '];
I f(I& x){return x=u[x]?f(u[x]):x;}
void j(p a){
	auto [x,y]=a;
	f(x)^f(y)?u[y]=x,n--:n;
}

I main(){
	cin>>n>>m>>k;
	set<p>s;
	R(m+k){
		cin>>x>>y;
		p a={min(x,y),max(x,y)};
		if(i<k)s.erase(a),e[i]=a;
		else s.insert(a);
	}
	for(p a:s)j(a);
	I r[k];
	R(k){
		r[i]=n;
		j(e[k-1-i]);
	}
	for(I i:r)cout<<i<<" ";
}
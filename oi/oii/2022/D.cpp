#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size)
#define ALL(x) x.begin(),x.end
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct node{
	ll d;
	vector<ll>s;
	node(ll t, ll x):d(0),s(4,0){
		if(t==0)s[0]+=x; // avanzar
		else d=x; // girar
	}
};

node oper(node a, node b){
	fore(i,0,4){
		a.s[(a.d+i)%4]+=b.s[i];
	}
	a.d=(a.d+b.d)%4;
	return a;
}
node NEUT=node(0,0);

struct STree{
	vector<node>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(ll l, ll r){
		node izq=NEUT, der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};

int main(){FIN;
	ll n; cin>>n;
	STree st(n);
	fore(i,0,n){
		ll t,x; cin>>t>>x; t--;
		st.upd(i,node(t,x));
	}
	ll q; cin>>q;
	while(q--){
		ll ty; cin>>ty; ty--;
		if(!ty){
			ll l,r; cin>>l>>r; r++;
			node res=st.query(l,r);
			ll x=res.s[0]-res.s[2],y=res.s[1]-res.s[3];
			cout<<x<<" "<<y<<" "<<res.d<<"\n";
		}
		else {
			ll i,t,x; cin>>i>>t>>x; t--;
			st.upd(i,node(t,x));
		}
	}
	return 0;
}

/*

g++ -O2 -std=c++17 -Wall -Wextra -g -D_GLIBCXX_DEBUG D.cpp -o a

*/

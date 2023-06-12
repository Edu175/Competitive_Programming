#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

struct node{
	ll res,pre[180],suf[180],sum;
	node(ll a):res(a),pre(180,0),suf(180,0),sum(a){pre[a]=1,suf[a]=1;}
	node(){}
};
ll add(ll a, ll b){
	ll ret=a+b;
	if(ret>=180)ret-=180;
	return ret;
}
node oper(node a, node b){ // a left, b right
	node p;
	p.res=max({a.res,b.res});
	vector<ll>c,d;
	fore(i,0,180){
		if(a.suf[i])c.pb(i);
		if(b.pre[i])d.pb(i);
	}
	for(auto i:c){
		ll lwb=lower_bound(ALL(d),180-i)-d.begin();
		ll x=d[lwb],y=d[add(lwb-1,180)]
		p.res=min({p.res,abs(180-i-x),abs(180-i-y)});
	}
	p.pre=a.pre;
	for(auto i:d)p.pre[add(i,a.sum)]=1;
	p.suf=b.suf;
	for(auto i:c)p.suf[add(i,b.sum)]=1;
	p.sum=add(a.sum,b.sum);
	return p;
}
node NEUT=node(0);
struct STree{
	vector<node> t; int n;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, int v){
		p+=n;
		for(t[p]=node(v);p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){ // [l, r)
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

struct UF{
	vv uf;ll q;
	UF(ll n):uf(n,-1),q(n){}
	ll find(ll x){return uf[x]<0?x:uf[x]=find(uf[x]);}
	void join(ll u, ll v){
		u=find(u),v=find(v);
		if(u==v)return;
		if(uf[u]>uf[v])swap(u,v);
		uf[u]+=uf[v]; uf[v]=u;
		q--;
	}
};

int main(){FIN;
	ll n,q; cin>>n>>q;
	UF all(n),red(n),blue(n);
	ll cr=0,cb=0;
	while(q--){
		ll ty,u,v; cin>>ty>>u>>v; u--,v--;
		all.join(u,v);
		if(ty==1)cr++,red.join(u,v);
		else cb++,blue.join(u,v);
		ll ner=blue.q-all.q;
		ll mxr=cr-ner;
		
		ll neb=red.q-all.q;
		ll mxb=cb-neb;
		
		ll tot=cr+cb-(n-all.q);
		ll res=min({mxr,mxb,tot/2});
		cout<<res*2<<"\n";
	}
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,szokput=b;i<szokput;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<endl;}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ll MOD;
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		b=mul(b,b); e>>=1;
	}
	return res;
}
ll pot(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res*=b;
		b*=b; e>>=1;
	}
	return res;
}
ll phi=1;
ll inv(ll x){
	assert(gcd(x,MOD)==1);
	return fpow(x,phi-1);
}
#define NEUT 0
#define oper max
struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	// void upd()
	void init(vector<ll>&a){
		fore(i,0,n)t[i+n]=a[i];
		for(ll i=n-1;i;i--)t[i]=oper(t[2*i],t[2*i+1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
int main(){FIN;
	ll n,q,m; cin>>n>>q>>m;
	MOD=m;
	vector<ll>ps,es;
	ll mi=m;
	for(ll i=2;i*i<=mi;i++){
		ll c=0;
		while(mi%i==0)mi/=i,c++;
		if(c)ps.pb(i),es.pb(c);
	}
	if(mi>1)ps.pb(mi),es.pb(1);
	imp(ps) imp(es)
	ll sz=SZ(ps);
	fore(i,0,sz){
		ll p=ps[i],e=es[i];
		phi*=pot(p,e-1)*(p-1);
	}
	vector<ll>a(n);
	vector<vector<ll>>b(sz,vector<ll>(n));
	fore(i,0,n)cin>>a[i];
	fore(i,0,n){
		fore(j,0,sz){
			auto p=ps[j];
			while(a[i]%p==0)a[i]/=p,b[j][i]++;
		}
	}
	imp(a);
	fore(i,0,sz){imp(b[i])}
	vector<STree>st(sz,STree(n));
	fore(i,0,sz)st[i].init(b[i]);
	vector<vector<ii>>dif(n);
	for(ll i=n-1;i>=0;i--){
		auto &v=dif[i];
		if(i<n-1)v=dif[i+1];
		v.insert(v.begin(),{i,0});
		vector<ii>u;
		fore(j,0,SZ(v)){
			v[j].snd=gcd(v[j].snd,a[i]);
			if(!SZ(u)||v[j].snd!=u.back().snd)u.pb(v[j]);
		}
		v=u;
		// v.pb({n,-1});
	}
	vector<ll>sp(n+1,1);
	fore(i,1,n+1){
		sp[i]=mul(sp[i-1],a[i-1]);
	}
	imp(sp);
	while(q--){
		ll l,r; cin>>l>>r; l--;
		ll res=1;
		fore(i,0,sz)res=mul(res,fpow(ps[i],st[i].query(l,r)));
		cout<<"\n"<<res<<"\n";
		res=mul(res,sp[r]);
		res=mul(res,inv(sp[l]));
		
		ll gs=1;
		auto &v=dif[l];
		fore(i,0,SZ(v)){
			ll idx=v[i].fst;
			if(idx>=r)break;
			ll nxt=i==SZ(v)-1?n:v[i+1].fst;
			nxt=min(nxt,r);
			gs=mul(gs,fpow(v[i].snd,nxt-idx));
		}
		res=mul(res,inv(gs));
		cout<<res<<"\n";
	}
	return 0;
}
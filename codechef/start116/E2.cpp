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
typedef pair<ll,ll> ii;
const ll INF=1e6;
typedef vector<ii> tn; // node type
typedef ll tl; // lazy type
tn unit(ll v){return {{-INF,0},{v,1}};}
#define NEUT {{-INF,0},{-INF,0}}
#define CLEAR 0 // cleared lazy node
tn oper(tn a, tn b){
	tn c;
	for(auto i:a)c.pb(i);
	for(auto i:b)c.pb(i);
	sort(ALL(c));
	tn d;
	for(auto i:c){
		if(!SZ(d)||i.fst!=d.back().fst)d.pb(i);
		else d.back().snd+=i.snd;
	}
	return tn(c.end()-2,c.end());
}
void acum(tl &a, tl v){ // accumulate lazy node
	a+=v;
}
tn calc(ll s, ll e, tn a, tl v){ // calculate STree range, a=previous value
	a[0].fst+=v;
	a[1].fst+=v;
	return a;
} 

struct STree{
	vector<tn>st; vector<tl>lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){
		//fore(i,0,n)upd(i,unit(0));
	}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(ll k, ll s, ll e, ll p, tn v){ // assign v to position p
		push(k,s,e);
		if(e<=p||p<s)return;
		if(e-s==1&&s==p){
			push(k,s,e);
			st[k]=v;
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,p,v),upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, tl v){
		//cout<<"[upd|"<<a<<","<<b<<"|"<<v<<"] ";
		upd(1,0,n,a,b,v);
	}
	void upd(ll p, tn v){upd(1,0,n,p,v);}
	tn query(ll a, ll b){return query(1,0,n,a,b);}
};
const ll MAXN=1e5+5;

vector<ll>g[MAXN];
ll S[MAXN],E[MAXN],D[MAXN];
vector<ll>ord,mov;
void dfs(ll x, ll f){
	S[x]=SZ(ord);
	ord.pb(x);
	for(auto y:g[x])if(y!=f){
		D[y]=D[x]+1;
		mov.pb(y);
		dfs(y,x);
		mov.pb(-y);
	}
	E[x]=SZ(ord);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		ord.clear();
		mov.clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		D[0]=0;
		mov.pb(0);
		dfs(0,-1);
		STree st(n);
		fore(i,0,n)st.upd(S[i],unit(D[i]));
		ll h=0;
		for(auto x:mov){
			ll ty=(x<0?-1:(x>0?1:0));
			x=abs(x);
			st.upd(0,n,ty);
			st.upd(S[x],E[x],-2*ty);
			h=max(h,st.query(0,n)[1].fst);
		}
		if(h==1){
			cout<<n*(n+2)<<"\n";
			continue;
		}
		//cout<<h;
		st=STree(n);
		fore(i,0,n)st.upd(S[i],unit(D[i]));
		ll res=0;
		for(auto x:mov){
			ll ty=(x<0?-1:(x>0?1:0));
			//cout<<"\n"<<x<<": ";
			x=abs(x);
			st.upd(0,n,ty);
			st.upd(S[x],E[x],-2*ty);
			if(ty<0)continue;
			auto r=st.query(0,n);
			//for(auto [i,j]:r)cout<<i<<","<<j<<" ";
			if(r[1].fst==h)res+=n+1;
			if(h!=1&&r[0].fst==h-1)res+=r[0].snd*3;
			if(h!=1&&r[1].fst==h-1)res+=r[1].snd*3;
		}
		//cout<<"\n";
		cout<<res<<"\n";
		//cout<<"\n";
	}
	return 0;
}

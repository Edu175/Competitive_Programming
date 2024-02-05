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

#define NEUT 0
#define CLEAR 0 // cleared lazy node
#define oper max

void acum(ll &a, ll v){ // accumulate lazy node
	a+=v;
}
ll calc(ll s, ll e, ll a, ll v){ // calculate STree range, a=previous value
	return a+v;
} 

struct STree{
	vector<ll>st,lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
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
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};

const ll MAXN=3e5+5;

vector<ll> g[MAXN];
vector<ll>ord,top;
ll S[MAXN],E[MAXN];
ll c[MAXN];

void dfs(ll x){
	S[x]=SZ(ord);
	ord.pb(x);
	for(auto y:g[x])dfs(y);
	E[x]=SZ(ord);
	top.pb(x);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		ord.clear();
		top.clear();
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		fore(i,0,n)cin>>c[i],c[i]--;
		dfs(0);
		STree st(n);
		set<ll>col[n];
		ll res=0;
		//imp(ord);
		for(auto x:top){
			for(auto it=col[c[x]].lower_bound(S[x]);
			it!=col[c[x]].end()&&*it<E[x];it++,col[c[x]].erase(prev(it))){
				auto y=ord[*it];
				st.upd(S[y],E[y],-1);
			}
			st.upd(S[x],E[x],1);
			col[c[x]].insert(S[x]);
			vector<ll>v={1,1};
			//cout<<x<<":\n";
			//fore(i,0,n)cout<<st.query(S[i],S[i]+1)<<" ";;cout<<"\n";
			for(auto y:g[x])v.pb(st.query(S[y],E[y]));
			//,cout<<y<<" "<<st.query(S[y],E[y])<<"\n";
			sort(ALL(v)); reverse(ALL(v));
			res=max(res,v[0]*v[1]);
		}
		cout<<res<<"\n";
	}
	return 0;
}

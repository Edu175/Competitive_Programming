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
#define oper min
#define NEUT 1
struct STree{
	vector<ll>st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void init(ll k, ll s, ll e, ll *a){
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]=v;return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};// uso: STree name(n);name.init(a);name.upd(i,v);name.query(s,e);
const ll MAXN=3e5+5;
ll r[MAXN],p[MAXN];
vector<ll>tr;
vector<ll>g[MAXN];
bool vis[MAXN];

void dfs(ll x){
	vis[x]=1;
	p[x]=SZ(tr);
	tr.pb(x);
	for(auto i:g[x]){
		if(!vis[i])dfs(i);
	}
	r[x]=SZ(tr);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		tr.clear();
		ll n; cin>>n;
		fore(i,0,n+3){
			g[i].clear();
			vis[i]=0;
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(0);
		STree st(n);
		fore(i,0,n)st.upd(i,0);
		/*imp(tr);
		fore(i,0,n)cout<<r[i]<<" ";
		cout<<"\n";
		fore(i,0,n)cout<<p[i]<<" ";
		cout<<"\n";*/
		ll god=n-1;
		ll q; cin>>q;
		while(q--){
			ll b; cin>>b;
			if(b==1){
				ll u; cin>>u; u--;
				ll v=st.query(p[u],p[u]+1);
				//cout<<u<<": "<<v<<": "<<p[u]+1<<" "<<r[u]<<" = "<<st.query(p[u]+1,r[u])<<" --> ";
				st.upd(p[u],st.query(p[u]+1,r[u]));
				//cout<<st.query(p[u],p[u]+1)<<"\n";
				if(v!=st.query(p[u],p[u]+1))god--;
			}
			else cout<<(god==-1?n-1:god)<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

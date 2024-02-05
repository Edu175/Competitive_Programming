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
ll oper(ll a, ll b){
	return a+b;
}
void acum(ll &a, ll v){ // accumulate lazy node
	a+=v;
}
ll calc(ll s, ll e, ll a, ll v){ // calculate STree range, a=previous value
	return a+(e-s)*v;
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
	void upd(ll a, ll b, ll v){
		upd(1,0,n,a,b,v);
		//if(a<=0&&0<b&&v)cout<<"w+"<<v<<" ";
	}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree
<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
ordered_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k
//less_equal for repeated elements (erase only with pointer)
const ll MAXN=2e5+5;
vector<ll> g[MAXN];
vector<ll>ord,top;
ll S[MAXN],E[MAXN];
ll fa[MAXN];

void dfs(ll x){
	S[x]=SZ(ord);
	ord.pb(x);
	for(auto y:g[x])if(y!=fa[x]){
		fa[y]=x;
		dfs(y);
	}
	top.pb(x);
	E[x]=SZ(ord);
}
ordered_set comp[MAXN]; ll id[MAXN];
void uf_init(ll n){
	fore(i,0,n){
		comp[i].insert(i);
		id[i]=i;
	}
}
bool uf_join(ll a, ll b){
	a=id[a], b=id[b];
	if(a==b)return 0;
	if(SZ(comp[a])>SZ(comp[b]))swap(a,b);
	for(auto i:comp[a])comp[b].insert(i), id[i]=b;
	comp[a].clear();
	return 1;
}
ll men[MAXN];//,may[MAXN];
vector<ll>mes[MAXN];
int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fa[0]=-1;
	dfs(0);
	uf_init(n);
	for(auto x:top){
		mes[x].resize(SZ(g[x]));
		fore(i,0,SZ(g[x]))if(g[x][i]!=fa[x]){
			mes[x][i]=comp[id[g[x][i]]].order_of_key(x);
			uf_join(x,g[x][i]);
		}
		ordered_set& st=comp[id[x]];
		men[x]=st.order_of_key(x);
		//may[x]=SZ(st)-1-men[x];
		//cout<<x<<": "<<men[x]<<"\n";
		//if(fa[x]!=-1)uf_join(x,fa[x]);
	}
	//cout<<SZ(ord)<<"\n";
	//imp(ord);
	STree st(n);
	fore(x,0,n){
		ll ma=x-men[x];//n-1-x-may[x];
		st.upd(S[x],E[x],ma);
		/*ll me=men[x];
		st.upd(0,S[x]+1,me);
		st.upd(E[x],n,me);*/
		fore(i,0,SZ(g[x]))if(g[x][i]!=fa[x]){
			ll y=g[x][i],val=mes[x][i];
			st.upd(0,S[y],val);
			st.upd(E[y],n,val);
		}
		//cout<<x<<": "<<"["<<S[x]<<","<<E[x]<<"),"<<ma<<" "<<"["<<0<<","<<S[x]+1<<"),"<<me<<" "<<"["<<E[x]<<","<<n<<"),"<<me<<"\n";
	}
	fore(i,0,n)cout<<st.query(S[i],S[i]+1)<<" ";
	cout<<"\n";
	return 0;
}

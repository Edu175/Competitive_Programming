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
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=1e5+5;

vector<ll> g[MAXN][2];

ll rt[2];
vector<ll>ord[2];
ll S[MAXN][2],E[MAXN][2];
void dfs(ll x, ll w){
	S[x][w]=SZ(ord[w]);
	ord[w].pb(x);
	for(auto y:g[x][w])dfs(y,w);
	E[x][w]=SZ(ord[w]);
}
#define NEUT 0
ll oper(ll a, ll b){return a+b;}
struct STree{ //persistent
	vector<int>st,L,R; ll n,rt;
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0){}
	ll new_node(ll v,ll l, ll r){
		ll ks=SZ(st);
		st.pb(v),L.pb(l),R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, ll v){
		ll ks=new_node(st[k],L[k],R[k]); // *
		if(s+1==e){st[ks]+=v;return ks;}
		ll m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(a<=s&&e<=b)return st[k];
		if(e<=a||b<=s)return NEUT;
		ll m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	ll upd(ll k, ll p, ll v){return rt=upd(k,0,n,p,v);} // update on root k (first root is 0)
	ll upd(ll p, ll v){return upd(rt,p,v);} // update on last root
	ll query(ll k, ll a, ll b){return query(k,0,n,a,b);}
};
int main(){FIN;
	ll n; cin>>n;
	fore(w,0,2)fore(i,0,n){
		ll p; cin>>p; p--;
		if(p==-1)rt[w]=i;
		else g[p][w].pb(i);
	}
	fore(w,0,2)dfs(rt[w],w);
	STree st(n);
	vector<ll>roots={0};
	for(auto x:ord[0]){
		roots.pb(st.upd(S[x][1],1));
	}
	LL res=0;
	fore(x,0,n){
		ll resi=st.query(roots[E[x][0]],S[x][1],E[x][1])
		       -st.query(roots[S[x][0]],S[x][1],E[x][1]);
		res+=resi;
		//cout<<x<<": "<<resi<<"\n";
	}
	cout<<res-n<<"\n";
	return 0;
}

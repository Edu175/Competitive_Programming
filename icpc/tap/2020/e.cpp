#include<bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

ll uf[MAXN];
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}

vv g[MAXN]; // only down
ll fa[MAXN],a[MAXN];
vv ls[MAXN];
#define oper(a,b) ((a)+(b))
#define NEUT 0
struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
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
ll ans[MAXN];
STree st(MAXN);
void dfs(ll x){
	for(auto l:ls[x])st.upd(l,+1);
	ans[x]=st.query(0,a[x]+1);
	
	for(auto y:g[x])dfs(y);
	
	for(auto l:ls[x])st.upd(l,-1);
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<array<ll,3>>ev;
	fore(i,0,n){
		cin>>a[i]>>fa[i];
		fa[i]--;
		if(!i)fa[i]=-1;
		else g[fa[i]].pb(i);
		ev.pb({a[i],0,i});
	}
	vv L(m),X(m);
	fore(i,0,m){
		ll x,l,r; cin>>x>>l>>r; x--;
		L[i]=l,X[i]=x;
		ev.pb({r,1,i});
	}
	sort(ALL(ev));
	mset(uf,-1);
	for(auto [A,ty,i]:ev){
		if(ty==0){ // desbloqueo el i
			for(auto j:g[i])uf[j]=i;
		}
		else { // party
			ll p=uf_find(X[i]);
			ls[p].pb(L[i]);
		}
	}
	dfs(0);
	fore(i,0,n)cout<<ans[i]<<" ";;cout<<"\n";
	return 0;
}
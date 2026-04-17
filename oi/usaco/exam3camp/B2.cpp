#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5;
bool ft[MAXN+1],s[MAXN];
void upd(int i0, bool v){
	s[i0]^=v;
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]^=v;
}
bool get(int i0){
	bool r=0;
	for(int i=i0;i;i-=i&-i)r^=ft[i];
	return r;
}
bool get_sum(int i0, int i1){
	return get(i1)^get(i0);
}
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
ll idk=0;
ll nod[MAXN],S[MAXN],E[MAXN];
vector<ii>g[MAXN];
void dfs(ll x, ll f=-1){
	S[x]=idk++;
	for(auto [y,i]:g[x])if(y!=f){
		nod[i]=y;
		dfs(y,x);
	}
	E[x]=idk;
}
bool in(ll x, ll y){return S[x]<=S[y]&&S[y]<E[x];}
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll>idx(m,-1);
	vector<ii>ed;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		ed.pb({u,v});
	}
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	ll k; cin>>k; k--;
	uf_init();
	ll cnt=0;
	fore(i,0,m){
		auto [u,v]=ed[i];
		if(uf_join(u,v))g[u].pb({v,i}),g[v].pb({u,i});
		else idx[i]=cnt++;
	}
	vector<ll>xdi(m);
	fore(i,0,m)if(idx[i]!=-1)xdi[idx[i]]=i;
	dfs(0);
	fore(i,0,n)upd(S[i],a[i]);
	auto inutil_get=[&](ll x){
		return idx[x]>60?0:(k>>idx[x]&1);
	};
	auto util_get=[&](ll x){
		x=nod[x];
		ll r=get_sum(S[x],E[x]);
		fore(i,0,62)if(k>>i&1){
			auto [u,v]=ed[xdi[i]];
			r^=in(x,u)^in(x,v);
		}
		return r;
	};
	auto query=[&](ll x){
		if(get_sum(0,n))return ll(-1);
		if(m-(n-1)<=61&&(k>>(m-(n-1)))>=1)return ll(-1);
		//if(m-(n-1)<=62&&(k>=(1ll<<(m-(n-1)))))return -1;
		if(idx[x]==-1)return util_get(x);
		else return inutil_get(x);
	};
	vector<ll>res(m);
	fore(i,0,m)cout<<query(i)<<" ";;cout<<"\n";
	ll q; cin>>q;
	while(q--){
		char c; cin>>c;
		ll v; cin>>v; v--;
		if(c=='M')upd(S[v],1);
		if(c=='K'){
			k=v;
		}
		if(c=='D'){
			cout<<query(v)<<"\n";
		}
	}
	return 0;
}

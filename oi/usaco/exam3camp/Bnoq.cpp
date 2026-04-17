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
	if(!v)return;
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
vector<ll> comp[MAXN]; ll id[MAXN];
void uf_init(ll n){
	fore(i,0,n){
		comp[i]={i};
		id[i]=i;
	}
}
bool uf_join(ll a, ll b){
	a=id[a], b=id[b];
	if(a==b)return 0;
	if(SZ(comp[a])>SZ(comp[b]))swap(a,b);
	for(auto i:comp[a])comp[b].pb(i), id[i]=b;
	comp[a].clear();
	return 1;
}

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
	ll k,ok=0; cin>>k; k--;
	uf_init(n);
	vector<ll>l(m,-1),r(m,-1);
	ll cnt=0;
	vector<ll>rep(n);
	fore(i,0,n)rep[i]=m+i;
	vector<ii>h(m);
	fore(i,0,m){
		auto [u,v]=ed[i];
		ll a=rep[id[u]],b=rep[id[v]];
		if(uf_join(u,v)){
			l[i]=comp[id[u]][0];
			r[i]=comp[id[u]].back();
			h[i]={a,b};
			rep[id[u]]=i;
		}
		else idx[i]=cnt++;
	}
	vector<ll>pos(n),xdi(m);
	fore(i,0,m)if(idx[i]!=-1)xdi[idx[i]]=i;
	fore(i,0,n)pos[comp[id[0]][i]]=i;
	fore(i,0,m){
		if(l[i]!=-1)l[i]=pos[l[i]],r[i]=pos[r[i]]+1;
	}
	fore(i,0,n)l.pb(pos[i]),r.pb(pos[i]+1);
	fore(i,0,n)upd(pos[i],a[i]);
//	fore(i,0,n)cout<<s[pos[i]]<<" ";;cout<<"\n";
//	imp(xdi);
	auto flip=[&](ll x){
		auto [u,v]=ed[x];
		upd(pos[u],1);
		upd(pos[v],1);
	};
	auto inutil_upd=[&](){
		fore(i,0,62)if((k>>i&1)!=(ok>>i&1))flip(xdi[i]);
		ok=k;
	};
	auto inutil_get=[&](ll x){
		if(idx[x]>=63)return 0;
		return k>>idx[x]&1;
	};
	auto util_get=[&](ll x){
		bool x0=get_sum(l[h[x].fst],r[h[x].fst]);
		bool x1=get_sum(l[h[x].snd],r[h[x].snd]);
//		cout<<"get "<<x<<": "<<h[x].fst<<","<<h[x].snd<<": "<<x0<<" "<<x1<<endl;
//		assert(!(x0^x1));
		return (ll)x0;
	};
	auto query=[&](ll x){
		if(get_sum(0,n))return ll(-1);
		if(m-n+1<63&&(k>>(m-(n-1)))>=1)return ll(-1);
		//if(m-(n-1)<=62&&(k>=(1ll<<(m-(n-1)))))return -1;
		if(idx[x]==-1)return util_get(x);
		else return inutil_get(x);
	};
//	imp(pos);
	inutil_upd();
	vector<ll>res(m);
	for(ll i=m-1;i>=0;i--){
		res[i]=query(i);
		if(idx[i]==-1&&res[i])flip(i);
	}
//	fore(i,0,n)cout<<s[pos[i]]<<" ";;cout<<endl;
	fore(i,0,m)cout<<res[i]<<" ";;cout<<"\n";
	ll q; cin>>q;
	while(q--){
		char c; cin>>c;
		ll v; cin>>v; v--;
		if(c=='M')upd(pos[v],1);
		if(c=='K'){
			k=v;
			inutil_upd();
		}
		if(c=='D'){
			cout<<query(v)<<"\n";
		}
	}
	return 0;
}

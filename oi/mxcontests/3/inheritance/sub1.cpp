#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,hgfmdg=b;i<hgfmdg;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sldhg:v)cout<<sldhg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1005;

struct UF{
	ll id[MAXN];
	vector<ll>comp[MAXN];
	UF(ll n){fore(i,0,n)id[i]=i,comp[i]={i};}
	void join(ll x, ll y){
		x=id[x],y=id[y];
		assert(x!=y);
		if(SZ(comp[x])<SZ(comp[y]))swap(x,y);
		for(auto i:comp[y])id[i]=x,comp[x].pb(i);
		comp[y].clear();
	}
};

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	vector<pair<ii,ii>>ed;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		ed.pb({{-w,i},{u,v}});
	}
	sort(ALL(ed));
	vector<UF>uf(k,UF(n));
	vector<ll>ans(m,-1);
	for(auto [par,ar]:ed){
		auto [x,y]=ar;
		ll idx=par.snd,p=-1;
		fore(i,0,k)if(uf[i].id[x]!=uf[i].id[y]){
			p=i; break;
		}
		if(p==-1)continue;
		ans[idx]=p;
		uf[p].join(x,y);
	}
	fore(i,0,m)cout<<ans[i]+1<<"\n";
	return 0;
}
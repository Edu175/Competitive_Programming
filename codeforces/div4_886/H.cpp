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
const ll MAXN=2e5+5;

vector<ll> comp[MAXN]; ll id[MAXN]; ll d[MAXN];
void uf_init(ll n){fore(i,0,n)comp[i]={i},id[i]=i,d[i]=0;}
ll flag=1;
bool uf_join(ll a, ll b, ll x){
	ll ida=id[a], idb=id[b];
	if(ida==idb){
		if(d[a]-d[b]!=x)flag=0;
		return 0;
	}
	if(SZ(comp[ida])>SZ(comp[idb]))swap(ida,idb),swap(a,b),x*=-1;
	ll dif=-d[a]+x+d[b];
	for(auto i:comp[ida])comp[idb].pb(i), id[i]=idb, d[i]+=dif;
	comp[ida].clear();
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		uf_init(n);
		flag=1;
		fore(i,0,m){
			ll u,v,x; cin>>u>>v>>x; u--,v--;
			uf_join(u,v,x);
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

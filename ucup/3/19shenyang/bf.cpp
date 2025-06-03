#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5;

vector<ii> g[MAXN];

set<ll>st;
ll n;
void good(ll x, ll d){
	// cout<<x<<" "<<d<<"\n";
	if(st.count(d))return;
	st.insert(d);
	if(SZ(st)>n+5)return;
	for(auto [y,w]:g[x]){
		// cout<<x<<"-> "<<y<<"\n";
		good(y,d+w);
	}
}

ll mod(ll a){
	return (a%n+n)%n;
}
int main(){
	JET
	ll m,q; cin>>n>>m>>q;
	fore(i,0,m){
		ll u,v; cin>>u>>v;
		ll w=v;
		u=mod(u),v=mod(u+v);
		assert(mod(u+w)==v);
		g[u].pb({v,w});
	}
	while(q--){
		ll x; cin>>x; x=mod(x);
		st.clear();
		good(x,0);
		if(SZ(st)>n+5)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
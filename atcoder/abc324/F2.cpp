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
typedef long double ld;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

vector<pair<ll,ii>> g[MAXN];

ii maxi(ii a, ii b){
	if(a.fst*b.snd>b.fst*a.snd)return a;
	return b;
}

int main(){FIN;
	cin>>n;
	ll m; cin>>m;
	fore(i,0,m){
		ll u,v,b,c; cin>>u>>v>>b>>c; u--,v--;
		g[u].pb({v,{b,c}});
	}
	set<ii>st;
	
	return 0;
}

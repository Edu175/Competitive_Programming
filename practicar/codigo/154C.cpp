#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll rnd(){
	return (ll(rand())<<48)|(ll(rand())<<32)|(ll(rand())<<16)|rand();
}
const ll MAXN=1e6+5;

vector<ll> g[MAXN];

int main(){FIN;
	ll n,m; cin>>n>>m;
	srand(175);
	ll r[n];
	fore(i,0,n)r[i]=rnd();
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	map<ll,ll>mp;
	ll h[n]={};
	fore(x,0,n){
		for(auto y:g[x])h[x]^=r[y];
		mp[h[x]]++;
	}
	//imp(h);
	ll res=0;
	fore(x,0,n){
		ll resi=0;
		for(auto y:g[x])resi+=(h[y]^r[x])==(h[x]^r[y]);
		//cout<<x<<": "<<resi<<"+";
		resi+=mp[h[x]]-1;
		//cout<<mp[h[x]]-1<<" = "<<resi<<"\n";
		res+=resi;
	}
	cout<<res/2<<"\n";
	return 0;
}

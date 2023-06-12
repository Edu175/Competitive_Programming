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
const ll MAXN=2e5+5;

vector<ll>g[MAXN];
ll s[MAXN];
ll dp[MAXN][4];

ll f0(ll x, ll k){
	ll &res=dp[x][0];
	res=s[x]*k;
	for(auto i:g[x]){
		res+=f0(i,k/SZ(g[x]));
	}
	cout<<x<<" "<<k<<" "<<res<<"\n";
	return res;
}
ll f(ll x,ll k){
	ll &res=dp[x][1];
	if(res>=0)return res;
	res=0;
	if(SZ(g[x])==0)return res=dp[x][0];
	vector<pair<ll,ll>>go;
	for(auto i:g[x]){
		go.pb({f(i,k/SZ(g[x])+1),i});
	}
	cout<<x<<" "<<k<<" "<<res<<":\n";
	for(auto i:go)cout<<i.fst<<","<<i.snd<<" ";
	cout<<"\n";
	sort(ALL(go));
	reverse(ALL(go));
	fore(i,0,k%SZ(g[x]))res+=go[i].fst;
	fore(i,k%SZ(g[x]),SZ(go))res+=dp[go[i].snd][0];
	cout<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		fore(i,0,n-1){
			ll p; cin>>p; p--;
			g[p].pb(i+1);
		}
		fore(i,0,n)cin>>s[i];
		mset(dp,-1);
		cout<<"f0:\n";
		f0(0,k);
		cout<<"\nf:\n";
		cout<<f(0,k)<<"\n";
		fore(i,0,n+2)g[i].clear();
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

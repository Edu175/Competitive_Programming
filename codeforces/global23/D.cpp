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
	ll &res=dp[x][2];
	if(res>=0)return res;
	res=s[x]*k;
	for(auto i:g[x]){
		res+=f0(i,k/SZ(g[x]));
	}
	//cout<<x<<" "<<k<<" "<<res<<"\n";
	return res;
}
ll f(ll x,ll k,ll b){
	ll &res=dp[x][b];
	if(res>=0)return res;
	res=0;
	if(SZ(g[x])==0)return res;
	vector<pair<ll,ll>>go;
	for(auto i:g[x]){
		go.pb({f(i,k/SZ(g[x])+1,1)+s[i],i});
	}
	//cout<<x<<" "<<k<<" "<<b<<":\n";
	//for(auto i:go)cout<<i.fst<<","<<i.snd<<" ";
	//cout<<"\n";
	sort(ALL(go));
	reverse(ALL(go));
	ll pik=k%SZ(g[x]);
	if(b&&!pik)pik=SZ(g[x]);
	//cout<<"agarro "<<pik<<"\n";
	fore(i,0,pik)res+=go[i].fst;
	fore(i,pik,SZ(go))res+=f(go[i].snd,k/SZ(g[x]),0);
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
		/*cout<<"f0:\n";
		cout<<f0(0,k)<<"\n\n";
		cout<<"\nf:\n";
		cout<<f(0,k,0)<<"\n\n";*/
		cout<<f0(0,k)+f(0,k,0)<<"\n";
		fore(i,0,n+2)g[i].clear();
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

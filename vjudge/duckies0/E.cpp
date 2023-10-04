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

vector<ll> g[MAXN];
ll c[MAXN],dp[MAXN];

ll f(ll x){
	ll &res=dp[x];
	if(res!=-1)return res;
	res=c[x];
	ll resi=0;
	for(auto y:g[x]){
		resi+=f(y);
	}
	//cout<<x<<":\n"; imp(g[x]); cout<<resi<<" "<<res;
	if(SZ(g[x]))res=min(res,resi);
	//cout<<": "<<res<<"\n\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		fore(i,0,n+3){
			g[i].clear();
			dp[i]=-1;
		}
		fore(i,0,n)cin>>c[i];
		fore(i,0,k){
			ll x; cin>>x; x--;
			c[x]=0;
		}
		fore(i,0,n){
			ll m; cin>>m;
			g[i].resize(m);
			fore(j,0,m)cin>>g[i][j],g[i][j]--;
		}
		fore(i,0,n)cout<<f(i)<<" ";
		cout<<"\n";
	}
	return 0;
}

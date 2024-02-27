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
const ll MAXN=1e5+5,INF=2*MAXN;
char a[MAXN];
vector<ll> g[MAXN];
ll dp[MAXN][2];

ll f(ll x, ll b){
	ll &res=dp[x][b];
	if(res!=-1)return res; //
	if(a[x]=='S'&&b){/*cout<<x<<" "<<b<<": "<<res<<"\n";*/return res=INF;}
	if(a[x]=='P'&&!b){/*cout<<x<<" "<<b<<": "<<res<<"\n";*/return res=INF;}
	res=0;
	for(auto y:g[x]){
		res+=min(f(y,b),1+f(y,b^1));
	}
	//cout<<x<<" "<<b<<": "<<res<<"\n";
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n+3){
			g[i].clear();
			dp[i][0]=dp[i][1]=-1;
		}
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		fore(i,0,n)cin>>a[i];
		ll res=min(f(0,0),f(0,1));
		cout<<res<<"\n";
	}
	return 0;
}

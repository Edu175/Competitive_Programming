#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,skopul=b;i<skopul;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2005,MAXM=1e6+5,MOD=1e9+7;

vector<ii>g[MAXN];
ll k=-1,flag=1;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll u;
int dp[1<<18][18];
ll f(ll mk, ll x, ll s){
	auto &res=dp[mk][x];
	if(res!=-1)return res;
	res=0;
	for(auto [y,i]:g[x]){
		
		if(y==s){
			ll c=__builtin_popcountll(mk);
			if(c>2){
				// cout<<"found "<<c<<": "<<mk<<" "<<x<<" "<<s<<"\n";
				if(k==-1)k=c;
				else flag&=k==c;
				res=add(res,1);
			}
		}
		else if(!(mk>>y&1))res=add(res,f(mk|(1ll<<y),y,s));
	}
	return res;
	
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	u=(1ll<<n)-1;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	// fore(i,0,n){
	// 	cout<<i<<": ";
	// 	for(auto j:g[i])cout<<j.fst<<" ";;cout<<"\n";
	// }
	ll res=0;
	fore(s,0,n){
		mset(dp,-1);
		res=add(res,f(1<<s,s,s));
	}
	if(!flag)cout<<"NIE\n";
	else if(!res)cout<<"BRAK\n";
	else {
		cout<<"TAK\n";
		// res=res*k*2%MOD;
		cout<<k<<" "<<res<<"\n";
	}
	return 0;
}
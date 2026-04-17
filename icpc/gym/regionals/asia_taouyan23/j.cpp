#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// problema de mierdaaaa 30 minutos para entenderlo
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=105;

vector<ii> g[MAXN];
ll a[MAXN],dp[MAXN];

ll f(ll x){
	auto &res=dp[x];
	if(res!=-1)return res;
	res=0;
	for(auto [y,w]:g[x])res=max(res,f(y)+w);
	res+=a[x];
	return res;
}
vv ans;
void build(ll x){
	ans.pb(x);
	auto res=f(x);
	res-=a[x];
	ll c=0,to=-1;
	for(auto [y,w]:g[x])if(res==dp[y]+w)c++,to=y;
	if(c>1)ans={-1};
	else if(c)build(to);
}

int main(){
	JET
	ll n,m;
	while(cin>>n){
		cin>>m;
		string s; cin>>s;
		ll id=0;
		ll v=0;
		for(auto i:s){
			if(i==',')a[id++]=v,v=0;
			else v=10*v+(i-'0');
		}
		a[id++]=v,v=0;
		// fore(i,0,n)cout<<a[i]<<" ";;cout<<"\n";
		assert(id==n);
		fore(i,0,n){
			g[i].clear();
			dp[i]=-1;
		}
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w;// u--,v--;
			g[u].pb({v,w});
		}
		ans.clear();
		ll res=-1,x=0;
		fore(i,0,n)if(f(i)>res)res=f(i),x=i;
		// fore(i,0,n)cout<<f(i)<<" ";;cout<<"\n";
		// cerr<<x<<" x\n";
		cout<<res<<",";
		build(x);
		if(ans==vv(1,-1))cout<<"M\n";
		else {
			fore(i,0,SZ(ans)){
				if(i)cout<<",";
				cout<<ans[i];
			}
			cout<<"\n";
		}
	}
	return 0;
}
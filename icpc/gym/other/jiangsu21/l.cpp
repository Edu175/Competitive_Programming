#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
const ll MOD=998244353;
ll mul(ll a, ll b){return a*b%MOD;}
ll fij[MAXN],res=1,a[MAXN];
vv g[MAXN]; // without fa

void dfs(ll x){
	set<ll>st;
	for(auto y:g[x]){
		dfs(y);
		st.insert(y);
	}
	ll sz=SZ(st)+1;
	vv fs;
	auto doit=[&](ll v){
		if(v==-1)return;
		sz--;
		if(!st.count(v))fs.pb(v);
	};
	doit(a[x]);
	for(auto y:g[x])doit(fij[y]);
	if(SZ(fs)>1)res=0;
	else if(SZ(fs))fij[x]=fs[0];
	fore(i,1,sz+1)res=mul(res,i);
}

int main(){
    JET
    int t; cin>>t;
    while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			fij[i]=-1;
		}
		res=1;
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		fore(i,0,n)cin>>a[i],a[i]--;
		dfs(0);
		// cout<<res<<"\n";
		// cout<<fij[0]<<"\n";
		if(fij[0]!=-1&&fij[0]!=0)res=0; // added
		cout<<res<<"\n";
    }
    return 0;
}

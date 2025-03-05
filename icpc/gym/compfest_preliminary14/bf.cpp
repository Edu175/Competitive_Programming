#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(v,a) memset((v),(a),sizeof(v))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=998244353,MAXN=2e5+5,MAXV=2e5+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

vector<ii> g[MAXN];

set<ll>st;
ll done=0;
void dfs(ll x, ll to, ll fa){
	// cerr<<"dfs "<<x<<" "<<to<<" "<<fa<<"\n";
	if(x==to){done=1;return;}
	for(auto [y,i]:g[x])if(y!=fa){
		st.insert(i);
		dfs(y,to,x);
		if(done)return;
		st.erase(i);
	}
}
set<ll> get(ll x, ll y){
	st.clear(); done=0;
	dfs(x,y,-1);
	return st;
}

ll pf(ll n){
	ll res=0;
	fore(i,2,n+1)if(n%i==0){
		res++;
		while(n%i==0)n/=i;
	}
	return res;
}

int main(){
    JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	ll res=0;
	fore(x,0,n)fore(y,0,x)fore(z,0,y){
		auto st=get(x,y);
		for(auto i:get(x,z))st.insert(i);
		ll d=gcd(a[x],gcd(a[y],a[z]));
		res+=pf(d)*SZ(st);
		cerr<<x<<" "<<y<<" "<<z<<": "<<d<<": "<<SZ(st)<<" "<<pf(d)<<"\n";
	}
	res%=MOD;
	cout<<res<<"\n";
    return 0;
}
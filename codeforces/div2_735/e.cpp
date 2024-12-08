#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353,MAXN=1e5+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int pm(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

vector<ll> g[MAXN];

ll n;
ll get(ll d){
	if(d==1)return pm(2,n-1);
	vv deg(n),val(n);
	queue<ll>q;
	fore(i,0,n){
		deg[i]=SZ(g[i]);
		if(deg[i]<=1)q.push(i);
	}
	while(SZ(q)){
		auto x=q.front(); q.pop();
		ll r=val[x]%d;
		if(r!=0&&r!=d-deg[x])return 0;
		for(auto y:g[x]){
			deg[y]--,val[y]+=!r;
			if(deg[y]==1)q.push(y);
		}
	}
	return 1;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		vv res(n+5);
		for(ll d=n;d;d--)if((n-1)%d==0){
			res[d]=get(d);
			for(ll i=2*d;i<SZ(res);i+=d)res[d]=sub(res[d],res[i]);
		}
		fore(i,1,n+1)cout<<res[i]<<" ";;cout<<"\n";
	}
	return 0;
}

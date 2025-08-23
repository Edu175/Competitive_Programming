#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MAXM=MAXN;

vector<ii> g[MAXN];
ll vis[MAXN],D[MAXN],lw[MAXN],c[MAXN];
ll vised[MAXM];
vv zs;
void dfst(ll x){ // D 0, vis 0, vised 0
	vis[x]=1;
	c[x]=1;
	lw[x]=D[x];
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(!vis[y]){ // tree edge
			D[y]=D[x]+1;
			dfst(y);
			c[x]+=c[y];
			if(lw[y]>=D[y]){ // bridge
				zs.pb(c[y]);
			}
		}
		lw[x]=min(lw[x],lw[y]); // sino D[y]
	}
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			vis[i]=0;
			D[i]=0;
			g[i].clear();
		}
		fore(i,0,m)vised[i]=0;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
		}
		ll res=0,tot=0;
		fore(i,0,n)if(!vis[i]){
			zs.clear();
			dfst(i);
			ll q=c[i];
			for(auto z:zs)res=max(res,(q-z)*z);
			tot+=q*(q-1)/2;
		}
		cout<<tot-res<<"\n";
	}
	return 0;
}
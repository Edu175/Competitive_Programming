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
vector<ii> dir={{1,0},{0,1},{-1,0},{0,-1}};
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ll n,m;
ii cv(ll x){return {x/m,x%m};}
ll cv(ii x){return x.fst*m+x.snd;}
bool aden(ii x){return x.fst>=0&&x.fst<n&&x.snd>=0&&x.snd<m;}

const ll MAXN=1e6+5;
ll a[MAXN],vis[MAXN];
ll sum=0;
void dfs(ll x){
	vis[x]=1;
	sum+=a[x];
	for(auto d:dir){
		ii yp=d+cv(x); ll y=cv(yp);
		if(aden(yp)&&!vis[y]&&a[y])dfs(y);
	}
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		fore(i,0,n*m)vis[i]=0;
		cin>>n>>m;
		fore(i,0,n*m)cin>>a[i];
		ll res=0;
		fore(i,0,n*m)if(!vis[i]&&a[i]){
			sum=0;
			dfs(i);
			res=max(res,sum);
		}
		cout<<res<<"\n";
	}
	return 0;
}
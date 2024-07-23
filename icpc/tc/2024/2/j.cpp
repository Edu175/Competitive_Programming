#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5;
vector<vv> G(MAXN);
vector <bool> vis(MAXN,false);
struct UF{
	ll n; vv t;
	UF(ll n): n(n), t(n,-1){}
	ll find(ll x){return t[x]<0?x:t[x]=find(t[x]);}
	ll size(ll x){return t[x]<0?-t[x]:size(t[x]=find(t[x]));}
	bool uni(ll x, ll y){
		x=find(x), y=find(y);
		if(x==y) return false;
		if(t[x]<t[y]) swap(x,y);
		t[x]+=t[y]; t[y]=x;
		return true;
	}
	
};
ll c=5;
void dfs(ll v){
	vis[v]=true;
	cout<<v<<" ";c--;
	for(ll x: G[v]){
		if(!vis[x] && c) dfs(x);
	}
}
int main(){
	JET
	int n,m; cin>>n>>m;
	UF uf(n);
	fore(i,0,m){
		int a,b;
		cin>>a>>b;
		a--, b--;
		G[a].pb(b);
		G[b].pb(a);
		uf.uni(a,b);
	}
	bool y=false;
	fore(i,0,n){
		if(uf.size(i)>=5){
			y=true; 
			dfs(i);	
			break;
		}
	}
	if(!y) cout<<"-1/n";
	return 0;
}
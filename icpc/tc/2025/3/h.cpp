#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
set<ll> g[30];
ll vis[30];
ll c[30];
bool dfs(ll v){
	vis[v]=1;

	for(auto u:g[v])if(vis[u]<2){
		if(vis[u]==1){ return false;}
		if(!dfs(u)) { return false;}
	}
	vis[v]=2;
	return true;
}
vv r;
map<ll,ll> M;
void topo(ll x){
	vis[x]=1;
	for(auto u: g[x]){
		if(!(vis[u])) topo(u);
	}
	M[x]=SZ(r);
	r.pb(x);
}
int main(){
	JET
	ll n; cin>>n;string s[n];
	fore(i,0,n) cin>>s[i];
	mset(vis,0);
	mset(c,0);
	fore(i,0,n-1){
		bool f=0;
		fore(j,0,min(SZ(s[i]),SZ(s[i+1])))if(s[i][j]!=s[i+1][j]){
			g[s[i][j]-'a'].insert(s[i+1][j]-'a');
			c[s[i+1][j]-'a']++;
			f=1;
			break;
		}
		if(!f && SZ(s[i])>SZ(s[i+1])) {cout<<"Impossible\n"; return 0;}
	}
	ll f=1;
	fore(i,0,26) if(!vis[i]) f&=dfs(i);
	if(!f) {cout<<"Impossible\n"; return 0;}
	mset(vis,0);
	fore(i,0,26) if(!vis[i]) topo(i);
	reverse(ALL(r));
	assert(SZ(r)==26);
	
	fore(i,0,26) cout<<char('a'+r[i]);
	cout<<"\n";
	return 0;
}

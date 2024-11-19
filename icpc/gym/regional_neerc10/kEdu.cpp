#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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
void pinchilon(){
	#ifdef ONLINE_JUDGE
	freopen("kgraph.in","r",stdin);
	freopen("kgraph.out","w",stdout);
	#endif
}
random_device rd;
mt19937 rng(rd());
const ll MAXN=1e4+5;
vv g[MAXN],t[MAXN];
ll col[MAXN],k,fail=0;
void dfs(ll x){
	vv is(k);
	for(auto y:t[x])if(col[y]!=-1)is[col[y]]=1;
	ll mex=-1;
	fore(i,0,k)if(!is[i]){mex=i;break;}
	if(mex==-1){fail=1;return;}
	col[x]=mex;
	for(auto y:t[x])if(!fail&&col[y]==-1)dfs(y);
}
int main(){pinchilon();
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	vv prio,rest;
	fore(x,0,n)k=max(k,SZ(g[x]));
	fore(x,0,n){
		if(SZ(g[x])==k)prio.pb(x);
		else rest.pb(x);
	}
	for(auto x:prio)for(auto y:g[x])if(SZ(g[y])==k)t[x].pb(y);
	if(k%2==0)k++;
	vv res;
	auto proba=[&]()->bool{
		for(auto x:prio)shuffle(ALL(t[x]),rng),col[x]=-1;
		fail=0;
		shuffle(ALL(prio),rng);
		for(auto x:prio)if(!fail&&col[x]==-1)dfs(x);
		if(fail)return 0;
		for(auto x:rest){
			set<ll>st;
			for(auto y:g[x])st.insert(col[y]);
			fore(c,0,SZ(g[x])+3)if(!st.count(c)){
				col[x]=c;
				break;
			}
		}
		return 1;
	};
	while(!proba());
	cout<<k<<"\n";
	fore(i,0,n)cout<<col[i]+1<<"\n";
}
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=4e5+5;
// Finds strongly connencted components , ord is a valid toposort of the component graph
vv g[MAXN], gt[MAXN], ordk;  //gt: transposed graph. ord: order for scc  
ll visk[MAXN], cmp[MAXN], truth[MAXN], qcmp = 0, N; //cmp[x]:scc of x.truth[x]:bool value for 2sat  
void dfsk(ll x, ll t){
	visk[x] = 1; if(t) cmp[x] = qcmp;
    for(auto y:t ? gt[x]:g[x])if(!visk[y]) dfsk(y,t);
    if(!t) ordk.pb(x);
}
void scc(){
	qcmp=0; ordk.clear(); fore(i,0,N)visk[i]=0;
    fore(i,0,N) if(!visk[i]) dfsk(i,0);
    reverse(ALL(ordk)); fore(i,0,N)visk[i]=0;
    for(auto x:ordk)if(!visk[x]) dfsk(x,1),qcmp++;
}
// 2SAT, first define n = 2 * vars
ll neg(ll x){return N-x-1;}
void add_or(ll x, ll y){   
    g[neg(x)].pb(y); g[neg(y)].pb(x);
    gt[x].pb(neg(y)); gt[y].pb(neg(x));
}
bool satis(){
    scc();
    fore(i,0,N){
        if(cmp[i] == cmp[neg(i)]) return false;
        truth[i] = cmp[i] > cmp[neg(i)];
    }
    return true;
}

vv dg[MAXN];
vv ord;
ll vis[MAXN];
ll good=1;
void dfs(ll x){
	vis[x]=1;
	for(auto y:dg[x]){
		if(!vis[y])dfs(y);
		else good&=vis[y]==2;
	}
	vis[x]=2;
	ord.pb(x);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		N=2*n;
		fore(i,0,N){
			dg[i].clear();
			g[i].clear(),gt[i].clear();
			vis[i]=0;
		}
		ord.clear();
		vector<array<ll,3>> re;
		fore(_,0,m){
			ll o,i,j; cin>>o>>i>>j; o--,i--,j--;
			if(!o)add_or(i,j);
			else add_or(neg(i),neg(j));
			re.pb({o,i,j});
		}
		if(!satis()){
			cout<<"NO\n";
			continue;
		}
		vv ty(n,-1);
		fore(i,0,n)ty[i]=!truth[i];
		good=1;
		for(auto [o,i,j]:re){
			if(ty[i]==ty[j]){
				good&=o==ty[i];
			}
			else {
				if(!ty[i])swap(i,j);
				if(!o)dg[i].pb(j);
				else dg[j].pb(i);
			}
		}
		assert(good==1);
		fore(i,0,n)if(!vis[i])dfs(i);
		if(!good)cout<<"NO\n";
		else {
			cout<<"YES\n";
			reverse(ALL(ord));
			vv pos(n);
			fore(i,0,n)pos[ord[i]]=i+1;
			fore(i,0,n){
				ll x=pos[i];
				if(ty[i])x=-x;
				cout<<x<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}

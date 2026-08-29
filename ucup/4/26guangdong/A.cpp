#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv; 

const ll MAXN=1e5+5;

vv g[MAXN];

ll col[MAXN];
ll visd[MAXN];
void dfs(ll x, ll c){
	visd[x]=1;
	for(auto y:g[x])if(!visd[y]){
		if(col[y]!=-1&&col[y]!=c)continue;
		col[y]=c;
		dfs(y,c);
	}
}

int main(){
    JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			col[i]=-1;
			visd[i]=0;
		}
		vv rts;
		fore(i,0,m){
			ll x; cin>>x; x--;
			col[x]=i;
			rts.pb(x);
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		if(n==1){
			cout<<"YES\n";
			cout<<col[0]+1<<"\n";
			continue;
		}
		queue<ll> q;
		vv deg(n),vis(n);
		fore(i,0,n){
			deg[i]=SZ(g[i]);
			if(deg[i]<=1)q.push(i);
		}
		vv done(n);
		while(SZ(q)){
			ll x=q.front(); q.pop();
			vis[x]=1;
			if(!deg[x])break; // center
			assert(deg[x]==1);
			ll fa=-1;
			for(auto y:g[x])if(!vis[y])fa=y;
			if(col[x]!=-1){
				if(!done[x]&&col[fa]==-1)col[fa]=col[x],done[x]=done[fa]=1;
			}
			else {
				if(col[fa]!=-1&&!done[fa])col[x]=col[fa],done[x]=done[fa]=1;
			}
			if(--deg[fa]==1){
				q.push(fa);
			}
		}
		ll good=1;
		for(auto r:rts)good&=done[r];
		if(!good){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		for(auto r:rts)if(!visd[r])dfs(r,col[r]);
		fore(i,0,n)cout<<col[i]+1<<" ";;cout<<"\n";
	}
    return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5;

/*int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}*/
ll cyc;
vector<ll> comp[MAXN]; ll id[MAXN],c[MAXN];
void uf_init(ll n){
	fore(i,0,n){
		comp[i]={i};
		id[i]=i;
	}
}
bool uf_join(ll a, ll b){
	ll ig=c[a]==c[b];
	a=id[a], b=id[b];
	if(a==b)return ig;
	if(SZ(comp[a])>SZ(comp[b]))swap(a,b);
	for(auto i:comp[a])comp[b].pb(i), id[i]=b, c[i]^=ig;
	comp[a].clear();
	return 0;
}
vector<ll>g[MAXN];
ll vis[MAXN];
vector<ll>v;
ll e,done=0;
void dfs1(ll x){
	if(done)return;
	vis[x]=1;
	v.pb(x);
	if(x==e){
		done=1;
		return;
	}
	for(auto y:g[x])if(!vis[y])dfs1(y);
	if(!done)v.pop_back();
}
vector<ll>sp;
bool is(vector<ll>d){
	sort(ALL(d));
	if(sp==d)return 1;
	return 0;
}
void dfs2(ll x, ll w){
	cout<<"dfs2 "<<x<<" "<<w<<endl;
	c[x]=w;
	vis[x]=1;
	for(auto y:g[x]){
		cout<<"edge "<<x<<" "<<y<<endl;
		if(!is({x,y})){
			if(!vis[y])dfs2(y,w^1);
			else assert(c[x]!=c[y]);
		}
		else if(!vis[y])dfs2(y,w);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
			c[i]=0;
		}
		uf_init(n);
		vector<ii>ed;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			ed.pb({u,v});
			g[u].pb(v);
			g[v].pb(u);
		}
		done=0;
		v.clear();
		ll l=0,r=n-1;
		ll avs=0;
		vector<ll>p(n,-1);
		vector<ll>ind;
		for(auto [x,y]:ed){
			if(uf_join(x,y)){
				avs++;
				cout<<"contrad "<<x<<" "<<y<<endl;
				if(!done){
					cout<<"armo dedse "<<x<<" hasta "<<y<<endl;
					e=y,dfs1(x);
					imp(v);
					r=SZ(v)-1;
					fore(i,0,SZ(v))p[v[i]]=i;
				}
				if(p[x]>p[y])swap(x,y);
				if(p[x]==-1&&p[y]==-1)r=-1;
				else if(p[x]==-1)ind.pb(p[y]);
				l=max(l,p[x]);
				r=min(r,p[y]);
			}
		}
		if(l>=r){
			cout<<"NO\n";
			continue;
		}
		ll izq=0,der=0;
		if(avs==0)sp={-1,-1};
		else if(avs==1)sp={v[0],v.back()};
		else {
			for(auto i:ind)if(i<=l)
			sp={v[l],v[l+1]};
		}
		sort(ALL(sp));
		cout<<"YES\n";
		fore(i,0,n)vis[i]=0,c[i]=0;
		dfs2(avs?sp[0]:0,1);
		fore(i,0,n){
			cout<<c[i];
		}
		cout<<"\n";
		cout<<endl;
	}
	return 0;
}

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

ll cyc=-1;
vector<ll> comp[MAXN]; ll id[MAXN],c[MAXN];
vector<ll>g[MAXN];
ll vis[MAXN];
vector<ll>v,p,fa;
void uf_init(ll n){
	fore(i,0,n){
		comp[i]={i};
		id[i]=i;
	}
}
bool uf_join(ll a, ll b){
	cout<<"join "<<a<<" "<<b<<endl;
	ll ig=c[a]==c[b];
	ll _a=a,_b=b;
	a=id[a], b=id[b];
	if(a==b)return ig;
	if(SZ(comp[a])>SZ(comp[b]))swap(a,b),swap(_a,_b);
	if(b==cyc)swap(a,b),swap(_a,_b);
	for(auto i:comp[a]){
		comp[b].pb(i), id[i]=b;
		c[i]^=ig;
		if(fa[_a]!=-1)fa[i]=fa[_a];
	}
	comp[a].clear();
	return 0;
}
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
set<ii>st;
void insert(ll x, ll y){
	if(x>y)swap(x,y);
	st.insert({x,y});
}
bool inserted(ll x, ll y){
	if(x>y)swap(x,y);
	return st.count({x,y});
}
void dfs2(ll x, ll f){
	vis[x]=1;
	fa[x]=f;
	for(auto y:g[x])if(inserted(x,y)&&!vis[y]&&p[y]==-1)dfs2(y,f);
}
vector<ll>sp;
bool is(vector<ll>d){
	sort(ALL(d));
	if(sp==d)return 1;
	return 0;
}
void dfs3(ll x, ll w){
	cout<<"dfs3 "<<x<<" "<<w<<endl;
	c[x]=w;
	vis[x]=1;
	for(auto y:g[x]){
		cout<<"edge "<<x<<" "<<y<<endl;
		if(!is({x,y})){
			if(!vis[y])dfs3(y,w^1);
			else assert(c[x]!=c[y]);
		}
		else if(!vis[y])dfs3(y,w);
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
		cyc=-1;
		ll l=0,r=n-1;
		ll avs=0;
		p=fa=vector<ll>(n,-1);
		for(auto [x,y]:ed){
			insert(x,y);
			if(uf_join(x,y)){
				avs++;
				cout<<"contrad "<<x<<" "<<y<<endl;
				imp(fa);
				if(!done){
					cout<<"armo dedse "<<x<<" hasta "<<y<<endl;
					cyc=id[x];
					e=y,dfs1(x);
					imp(v);
					r=SZ(v)-1;
					fore(i,0,SZ(v))p[v[i]]=i;
					fore(i,0,n)vis[i]=0;
					for(auto i:v)dfs2(i,i);
				}
				x=fa[x],y=fa[y];
				cout<<"now "<<x<<" "<<y<<endl;
				if(x==-1&&y==-1){r=-1;continue;}
				else assert(x!=-1&&y!=-1);
				if(p[x]>p[y])swap(x,y);
				l=max(l,p[x]);
				r=min(r,p[y]);
			}
		}
		if(l>=r){
			cout<<"NO\n";
			continue;
		}
		if(avs==0)sp={-1,-1};
		else if(avs==1)sp={v[0],v.back()};
		else sp={v[l],v[l+1]};
		sort(ALL(sp));
		cout<<"YES\n";
		fore(i,0,n)vis[i]=0,c[i]=0;
		dfs3(avs?sp[0]:0,1);
		fore(i,0,n){
			cout<<c[i];
		}
		cout<<"\n";
		cout<<endl;
	}
	return 0;
}

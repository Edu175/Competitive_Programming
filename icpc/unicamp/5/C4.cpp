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

vector<ii> g[MAXN];

vector<ll>path,v;
ll vis[MAXN],c[MAXN];
ll done=0;
void build(ll y){
	ll flag=0;
	for(auto i:path){
		if(i==y)flag=1;
		if(flag)v.pb(i);
	}
};
void dfs1(ll x){
	if(done)return;
	vis[x]=1;
	path.pb(x);
	for(auto [y,i]:g[x])if(!done){
		//cout<<x<<" --> "<<y<<"\n";
		if(!vis[y])c[y]=c[x]^1,dfs1(y);
		else if(c[x]==c[y])build(y),done=1;
	}
	path.pop_back();
}

ii sp;
void dfs2(ll x){
	vis[x]=1;
	//cout<<"dfs2 "<<x<<": "<<c[x]<<"\n";
	for(auto [y,i]:g[x]){
		bool esp=((ii){x,y}==sp||(ii){y,x}==sp);
		//cout<<x<<" --> "<<y<<" ("<<esp<<") "<<c[x]<<" "<<c[y]<<endl;
		if(!vis[y])c[y]=c[x]^1^esp,dfs2(y);
		else assert(c[x]!=(c[y]^esp));
	}
}

void color(ll x, ll n){
	c[x]=1;
	dfs2(x);
	cout<<"YES\n";
	fore(i,0,n)cout<<c[i];
	cout<<"\n";
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			vis[i]=c[i]=0;
		}
		vector<ii>ed;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
			ed.pb({u,v});
		}
		path.clear();
		v.clear();
		done=0;
		dfs1(0);
		fore(i,0,n){
			vis[i]=c[i]=0;
		}
		if(!done){
			color(0,n);
			continue;
		}
		vector<ll>p(n,-1),vised(m,0);
		fore(i,0,SZ(v))p[v[i]]=i;
		
		queue<ll>can;
		fore(i,0,SZ(v)){
			auto x=v[i];
			c[x]=i&1;
			for(auto [y,j]:g[x]){
				if(i<SZ(v)-1&&y==v[i+1])vised[j]=1;
				else if(!vised[j])can.push(j);
			}
		}
		vector<ii>dif,ig;
		while(SZ(can)){
			auto i=can.front(); can.pop();
			auto [x,y]=ed[i];
			//cout<<"edge "<<x<<" "<<y<<"\n";
			vised[i]=1;
			if(p[x]!=-1&&p[y]!=-1){
				if(c[x]==c[y])ig.pb({p[x],p[y]});
				else dif.pb({p[x],p[y]});
			}
			else {
				assert(p[x]!=-1||p[y]!=-1);
				if(p[x]==-1)swap(x,y);
				p[y]=p[x];
				c[y]=c[x]^1;
				for(auto [z,j]:g[y])if(!vised[j])can.push(j);
			}
		}
		ll l=0,r=n;
		for(auto [s,e]:ig){
			if(s>e)swap(s,e);
			l=max(l,s);
			r=min(r,e);
		}
		vector<ll>ev(n);
		for(auto [s,e]:dif){
			if(s>e)swap(s,e);
			ev[s]++;
			ev[e]--;
		}
		ll sum=0;
		sp={-1,-1};
		fore(i,0,n){
			sum+=ev[i];
			if(sum==0&&l<=i&&i<r){sp={v[i],v[i+1]};break;}
		}
		imp(v);
		for(auto i:ig)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		for(auto i:dif)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		cout<<l<<" "<<r<<"\n";
		cout<<sp.fst<<","<<sp.snd<<"\n";
		if(sp.fst==-1){
			cout<<"NO\n";
			continue;
		}
		color(sp.fst,n);
	}
	return 0;
}

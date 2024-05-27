#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dkjgh:v)cout<<dkjgh<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=105,INF=MAXN*1e4;

vector<ii>g[MAXN];

ll tk[MAXN];
ll d[MAXN];
ll D[MAXN],F[MAXN];
ll n;
void dfs1(ll x, ll f=-1){
	for(auto [y,fdrt]:g[x])if(y!=f){
		D[y]=D[x]+1;
		F[y]=x;
		dfs1(y,x);
	}
}
void dfs(ll x){
	for(auto [y,w]:g[x])if(!tk[y]&&d[y]==-1){
		d[y]=d[x]+w;
		dfs(y);
	}
}

ll get(ll x){
	mset(d,-1);
	d[x]=0;
	dfs(x);
	ll mx=x;
	fore(i,0,n)if(d[i]>d[mx])mx=i;
	mset(d,-1);
	d[mx]=0;
	dfs(mx);
//	cout<<mx<<" ";
	fore(i,0,n)if(d[i]>d[mx])mx=i;
//	cout<<"get "<<x<<": "<<d[mx]<<"\n";
	return d[mx];
}

int main(){FIN;
	cin>>n;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	F[0]=-1;
	dfs1(0);
	ll q; cin>>q;
	while(q--){
		ll x,y; cin>>x>>y; x--,y--;
		if(D[x]<D[y])swap(x,y);
		vector<ll>p;
		ll _x=x,_y=y;
		while(D[x]>D[y])x=F[x],p.pb(x);
		if(SZ(p)&&x==y)p.pop_back();
		while(x!=y){
//			cout<<x<<" "<<y<<endl;
			x=F[x],y=F[y];
			p.pb(x),p.pb(y);
		}
		ll res=INF;
		for(auto i:p){
			tk[i]=1;
//			cout<<i<<": ";
			res=min(res,abs(get(_x)-get(_y)));
			tk[i]=0;
		}
//		imp(p);
		if(res>=INF)res=-1;
		cout<<res<<"\n";
	}
	return 0;
}

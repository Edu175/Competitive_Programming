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
const ll MAXN=1e6+5;

ll n,m;
ll cv(ii a){return a.fst*m+a.snd;}
ii cv(ll a){return {a/m,a%m};}


ll bl[MAXN]; // blocked
ll k;
vector<ii> dir={{1,0},{0,1},{-1,0},{0,-1}};

vv vec(ll x){
	vector<ll> ret;
	for(auto d:dir){
		ii yp=cv(x);
		yp.fst+=d.fst; yp.snd+=d.snd;
		if(yp.fst<0||yp.fst>=n)continue;
		if(yp.snd<0||yp.snd>=m)continue;
		ll y=cv(yp);
		if(bl[y])continue;
		ret.pb(y);
	}
	return ret;
}

void bfs(vv s){
	vv d(n*m,-1);
	queue<ll> q;
	for(auto i:s)q.push(i),d[i]=0;
	fore(i,0,n)fore(j,0,m)if(!i||i==n-1||!j||j==m-1){
		ll x=cv({i,j});
		if(d[x]==-1)q.push(x),d[x]=1;
	}
	while(SZ(q)){
		auto x=q.front(); q.pop();
		// auto xp=cv(x);
		// cout<<xp.fst<<","<<xp.snd<<": "<<d[x]<<"\n";
		if(d[x]>k)return;
		bl[x]=1;
		for(auto y:vec(x))if(d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
}

ll vis[MAXN];
ll tam=0;
void dfs(ll x){
	tam++;
	vis[x]=1;
	for(auto y:vec(x))if(!vis[y])dfs(y);
}

int main(){FIN;
	ll t; cin>>t;
	fore(__,0,t){
		cout<<"Case #"<<__+1<<": ";
		cin>>n>>m>>k;
		vv s;
		fore(i,0,n*m){
			char c; cin>>c;
			bl[i]=c=='#';
			if(bl[i])s.pb(i);
			vis[i]=0;
		}
		bfs(s);
		ll res=0;
		fore(i,0,n*m)if(!bl[i]&&!vis[i]){
			tam=0;
			dfs(i);
			res=max(res,tam);
		}
		cout<<res<<"\n";
	}
	return 0;
}

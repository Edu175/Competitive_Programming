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
const ll INF=1e9;
struct MinQ{ // O(1) amortized
	vector<ii>q; ll dif=0,po=0;
	MinQ(){}
	void push(ll x){
		x-=dif;
		ll cnt=1;
		while(po<SZ(q)&&x<=q.back().fst)cnt+=q.back().snd,q.pop_back();
		q.pb({x,cnt});
	}
	void pop(){
		if(po==SZ(q))return;
		if(q[po].snd>1)q[po].snd--;
		else po++;
	}
	ll query(){
		if(po==SZ(q))return INF;
		return q[po].fst+dif;
	}
	void add(ll x){dif+=x;}
};
vv vis;
vector<vv> g;
ll z=0;
void dfs(ll x){
	z++; vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
}

bool good(ll x){
	string s=to_string(x);
	return count(ALL(s),'4')+count(ALL(s),'7')==SZ(s);
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	g.clear(); g.resize(n);
	vis.clear(); vis.resize(n);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	map<ll,ll> mp;
	fore(i,0,n)if(!vis[i]){
		z=0;
		dfs(i);
		mp[z]++;
	}
	vv dp(n+1,INF); dp[0]=0;
	for(auto [z,c]:mp){
		vector<MinQ> qs(z);
		fore(i,0,n+1){
			auto &q=qs[i%z];
			q.add(1);
			q.push(dp[i]);
			dp[i]=q.query();
			if(i-z*c>=0)q.pop();
		}
	}
	ll res=INF;
	fore(i,1,n+1)if(good(i))res=min(res,dp[i]);
	res--;
	if(res>=INF-100)res=-1;
	cout<<res<<"\n";
	return 0;
}
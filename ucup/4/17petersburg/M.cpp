#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(a) {for(auto i:a)cout<<i<<" ";cout<<"\n";}
#define impr(a) {for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll INF=1e6;
struct FF{ // Ford-Fulkerson
	ll n;
	struct edge{int to,rev; ll f,c;}; // c can be negative!!
	vector<vector<edge>> g;
	vector<bool> vis;
	ll F=0;
	FF(ll n):n(n),g(n),vis(n){}
	void add_edge(int x, int y, ll c){
		g[x].pb({y,SZ(g[y]),0,c});
		g[y].pb({x,SZ(g[x])-1,0,0});
	}
	ll t;
	bool dfs(ll x){
		vis[x]=1;
		if(x==t)return 1;
		for(auto &e:g[x])if(e.f<e.c&&!vis[e.to]){
			if(dfs(e.to)){ // paso una unidad
				e.f++;
				g[e.to][e.rev].f--;
				return 1;
			}
		}
		return 0;
	}
	bool augment(ll s, ll _t, ll dst){ // dst = desired max flow
		t=_t;
		vis=vector<bool>(n);
		while(F<dst&&dfs(s)){
			F++;
			vis=vector<bool>(n);
		}
		// cerr<<"augmented "<<s<<" "<<t<<" to "<<dst<<":\n";
		// fore(x,0,n)for(auto e:g[x])if(e.c>0||e.f)cerr<<x<<"->"<<e.to<<": "<<e.f<<"/"<<e.c<<"\n";
		// cerr<<"= "<<F<<"\n\n";
		
		return F==dst;
	}
};

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll a,b,m; cin>>a>>b>>m;
		ll tam=2*m;
		vv ini(tam);
		vector<ii> rans;
		fore(i,0,m){
			ll ty,l,r; cin>>ty>>l>>r; l--;
			fore(j,l,r)ini[j]++;
			if(ty==1)rans.pb({l,r});
		}
		// imp(ini)
		// impr(rans)
		vector<ii> wh; // x,i
		ll nodes=tam+3,s=nodes+1,t=nodes+2;
		FF fl(nodes+5);
		ll F=min(b,m);
		ll lw=0;
		fore(x,0,tam){
			ll cap=a-ini[x];
			lw=max(lw,-cap);
			fl.add_edge(x,x+1,cap+F);
		}
		fl.add_edge(s,0,INF);
		fl.add_edge(tam,t,INF);
		for(auto [l,r]:rans)fl.add_edge(l,r,1);
		ll good=0;
		if(F>=lw&&fl.augment(s,t,F))good=1;
		if(good)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}

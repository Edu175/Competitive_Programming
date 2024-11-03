#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const int MAXN=1e6+5;

struct edge{
	int y;
	list<edge>::iterator rev;
	edge(int y):y(y){}
};
list<edge> g[MAXN];
void add_edge(int a ,int b){
	g[a].push_front(edge(b));
	auto ia=g[a].begin();
	g[b].push_front(edge(a));
	auto ib=g[b].begin();
	ia->rev=ib;ib->rev=ia;
}
vector<int> p;
void go(int x){
	while(g[x].size()){
		int y=g[x].front().y;
		g[y].erase(g[x].front().rev);
		g[x].pop_front();
		go(y);
	}
	p.push_back(x);
}
vector<int> get_path(int x){
	p.clear();go(x);reverse(p.begin(),p.end());
	return p;
}
ii ed[MAXN];
ll us[MAXN];
ll c[MAXN];

vector<ii>gr[MAXN];
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto [y,i]:gr[x])if(!vis[y]){
		dfs(y);
		if(c[y]){
			c[x]^=1;
			c[y]^=1;
			us[i]=1;
		}
	}
}
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll N,M; cin>>N>>M;
	ll ok=0;
	while(1){
		ll n=rng()%N+1,m=rng()%M+1;
		vector<ii>eul;
		vector<ll>ts;
		fore(i,0,m){
			ll u=rng()%n,v=rng()%(n-1),ty=rng()&1;
			if(v>=u)v++;
			if(rng()&1)swap(u,v);
			if(ty)c[u]^=1,c[v]^=1,eul.pb({u,v});
			else {
				gr[u].pb({v,i});
				gr[v].pb({u,i});
			}
			ed[i]={u,v};
			ts.pb(ty);
		}
		ll flag=1;
		fore(i,0,n)if(!vis[i]){
			dfs(i);
			flag&=!c[i];
		}
		if(!flag){
			cout<<"N\n";
			return 0;
		}
		cout<<"S\n";
		fore(i,0,m)if(us[i])eul.pb(ed[i]);
		for(auto [u,v]:eul)add_edge(u,v);
		map<ii,vector<ll>>mp;
		fore(i,0,m){
			auto [u,v]=ed[i];
			mp[{u,v}].pb(i);
			// mp[{v,u}].pb(i);
		}
		vector<ll>res(m);
		auto assign=[&](ll i, ll x, ll y){
			if(ed[i]==ii({x,y}))res[i]=1;
			else res[i]=-1;
		};
		// for(auto [ar,v]:mp){
		// 	cout<<ar.fst<<","<<ar.snd<<": ";
		// 	imp(v);
		// }
		auto get_idx=[&](ll x, ll y){
			// cout<<"get_idx "<<x<<","<<y<<":"<<endl;
			auto &v=mp[{x,y}];
			ll res=-1;
			if(SZ(v))res=v.back(),v.pop_back();
			else {
				auto &u=mp[{y,x}];
				res=u.back(),u.pop_back();
			}
			// cout<<res<<endl;
			return res;
		};
		vector<ll>vis(n);
		fore(i,0,n)if(!vis[i]){
			auto p=get_path(i);
			// imp(p)
			fore(i,0,SZ(p)-1){
				ll x=p[i],y=p[(i+1)%SZ(p)];
				assign(get_idx(x,y),x,y);
			}
			for(auto i:p)vis[i]=1;
		}
		fore(i,0,m)cout<<res[i]<<" ";;cout<<"\n";
		
		
		//check
		vector<ll>sal(n);
		fore(i,0,m)if(res[i]){
			sal[ed[i].fst]+=res[i];
			sal[ed[i].snd]-=res[i];
		}
		fore(i,0,n)if(!sal[i]){
			cout<<"FAILED!!!\nInput:\n";
			cout<<n<<" "<<m<<"\n";
			fore(i,0,m)cout<<ed[i].fst+1<<" "<<ed[i].snd+1<<" "<<ts[i]<<"\n";
			exit(0);
		}
		cout<<"ok "<<++ok<<"\n";
	}
	return 0;
}
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
typedef int ll;
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
vector<ll>ids[MAXN];
int main(){
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v,ty; cin>>u>>v>>ty; u--,v--;
		if(ty)c[u]^=1,c[v]^=1,us[i]=1;
		else {
			gr[u].pb({v,i});
			gr[v].pb({u,i});
		}
		ed[i]={u,v};
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
	fore(i,0,m)if(us[i])add_edge(ed[i].fst,ed[i].snd);
	vector<pair<ii,ll>>h;
	fore(i,0,m)if(us[i]){
		auto [u,v]=ed[i];
		h.pb({ed[i],i});
		// mp[{v,u}].pb(i);
	}
	sort(ALL(h));
	ll w=h[0].snd;
	fore(i,0,SZ(h)){
		if(!i||h[i].fst!=h[i-1].fst)w=h[i].snd;
		ids[w].pb(h[i].snd);
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
		ii ar={x,y};
		pair<ii,ll>fi={ar,-1};
		auto it=lower_bound(ALL(h),fi);
		ll w=-1;
		if(it!=h.end()&&it->fst==ar)w=it->snd;
		ll res=-1;
		if(w!=-1&&SZ(ids[w]))res=ids[w].back(),ids[w].pop_back();
		else {
			fi={{y,x},-1};
			w=lower_bound(ALL(h),fi)->snd;
			res=ids[w].back(),ids[w].pop_back();
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
	
	return 0;
}




/*
S
0,1: 0 
0,2: 1 
1,3: 3 
2,1: 2 
2,3: 4 
0 2 3 1 0 
get_idx 0,2:
1
get_idx 2,3:
4
get_idx 3,1:
3
get_idx 1,0:
0
get_idx 0,0:
/usr/include/c++/9/debug/vector:457:
In function:
    std::__debug::vector<_Tp, _Allocator>::reference 
    std::__debug::vector<_Tp, _Allocator>::back() [with _Tp = long long int; 
    _Allocator = std::allocator<long long int>; std::__debug::vector<_Tp, 
    _Allocator>::reference = long long int&]

Error: attempt to access an element in an empty container.

Objects involved in the operation:
    sequence "this" @ 0x0x563435d79730 {
      type = std::__debug::vector<long long, std::allocator<long long> >;
    }
Aborted (core dumped)




*/
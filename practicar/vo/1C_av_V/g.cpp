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
const ll B=30;
struct matrix{
	vector<ll>x;
	matrix(): x(B){}
	ll add(ll v){
		if(v==0)return 0;
		for(ll j=B-1;j>=0;j--)v=min(v,v^x[j]);
		if(v){x[__lg(v)]=v;return __lg(v);}
		return -1;
	}
};
struct UnionFind {
	int n,comp;
	vector<int> uf,si;
	vector<ii> c;
	vector<matrix> ms;
	vv we;
	// vector<vector<int>> pos;
	UnionFind(int n=0):n(n),comp(n),uf(n),si(n,1),ms(n),we(n){
		fore(i,0,n)uf[i]=i;}
	int find(int x){return x==uf[x]?x:find(uf[x]);}
	ll getx(int x){return x==uf[x]?0:we[x]^getx(uf[x]);}
	ll path(int x, int y){return getx(x)^getx(y);}
	bool join(int x, int y, ll w){
		ll val=path(x,y)^w;
		if((x=find(x))==(y=find(y))){
			c.pb({x,ms[x].add(val)});
			return false;
		}
		if(si[x]<si[y])swap(x,y);
		si[x]+=si[y];uf[y]=x;comp--;c.pb({y,-2});
		we[y]=val;
		
		fore(i,0,B){
			ll v=ms[y].x[i];
			if(!v)continue;
			c.pb({x,ms[x].add(v)});
		}
		
		return true;
	}
	int snap(){return c.size();}
	void rollback(int snap){
		while(SZ(c)>snap){
			auto [x,p]=c.back();c.pop_back();
			if(p==-2){
				si[uf[x]]-=si[x];
				uf[x]=x;comp++;
			}
			else if(p!=-1)ms[x].x[p]=0;
		}
	}
};
enum {ADD,DEL,QUERY};
struct Query {int type,x,y,w;};
struct DynCon {
	vector<Query> q;
	UnionFind dsu;
	vector<int> mt;
	map<pair<int,int>,int> last;
	DynCon(int n):dsu(n){}
	void add(int x, int y, ll w){
		if(x>y)swap(x,y);
		q.pb((Query){ADD,x,y,w});mt.pb(-1);last[{x,y}]=q.size()-1;
	}
	void remove(int x, int y, ll w){
		if(x>y)swap(x,y);
		q.pb((Query){DEL,x,y,w});
		int pr=last[{x,y}];mt[pr]=q.size()-1;mt.pb(pr);
	}
	void query(int x, int y){q.pb((Query){QUERY,x,y,-1});mt.pb(-1);}
	void process(){ // answers all queries in order
		if(!q.size())return;
		fore(i,0,q.size())if(q[i].type==ADD&&mt[i]<0)mt[i]=q.size();
		go(0,q.size());
	}
	void go(int s, int e){
		if(s+1==e){
			if(q[s].type==QUERY){
				auto [asd,x,y,asdd]=q[s];
				assert(dsu.find(x)==dsu.find(y));
				auto mt=dsu.ms[dsu.find(x)];
				auto v=dsu.path(x,y);
				for(ll j=B-1;j>=0;j--)v=min(v,v^mt.x[j]);
				cout<<v<<"\n";
			} // answer query using DSU
			return;
		}
		int k=dsu.snap(),m=(s+e)/2;
		for(int i=e-1;i>=m;--i)if(mt[i]>=0&&mt[i]<s)dsu.join(q[i].x,q[i].y,q[i].w);
		go(s,m);dsu.rollback(k);
		for(int i=m-1;i>=s;--i)if(mt[i]>=e)dsu.join(q[i].x,q[i].y,q[i].w);
		go(m,e);dsu.rollback(k);
	}
};

int main(){FIN;
	ll n,m; cin>>n>>m;
	DynCon dc(n);
	map<ii,ll>mp;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		dc.add(u,v,w);
		if(u>v)swap(u,v);
		mp[{u,v}]=w;
	}
	ll q; cin>>q;
	while(q--){
		ll ty,u,v; cin>>ty>>u>>v; u--,v--;
		if(u>v)swap(u,v);
		if(ty==1){
			ll w; cin>>w;
			dc.add(u,v,w);
			mp[{u,v}]=w;
		}
		if(ty==2)dc.remove(u,v,mp[{u,v}]);
		if(ty==3)dc.query(u,v);
	}
	dc.process();
	return 0;
}

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
struct UnionFind {
	int n,comp;
	vector<int> uf,si,c;
	UnionFind(int n=0):n(n),comp(n),uf(n),si(n,1){
		fore(i,0,n)uf[i]=i;}
	int find(int x){return x==uf[x]?x:find(uf[x]);}
	bool join(int x, int y){
		if((x=find(x))==(y=find(y)))return false;
		if(si[x]<si[y])swap(x,y);
		si[x]+=si[y];uf[y]=x;comp--;c.pb(y);
		return true;
	}
	int snap(){return c.size();}
	void rollback(int snap){
		while(SZ(c)>snap){
			int x=c.back();c.pop_back();
			si[uf[x]]-=si[x];uf[x]=x;comp++;
		}
	}
};
enum {ADD,DEL,QUERY};
struct Query {int type,x,y;};
struct DynCon {
	vector<Query> q;
	UnionFind dsu;
	vector<int> mt;
	map<pair<int,int>,int> last;
	DynCon(int n):dsu(n){}
	void add(int x, int y){
		if(x>y)swap(x,y);
		q.pb((Query){ADD,x,y});mt.pb(-1);last[{x,y}]=q.size()-1;
	}
	void remove(int x, int y){
		if(x>y)swap(x,y);
		q.pb((Query){DEL,x,y});
		int pr=last[{x,y}];mt[pr]=q.size()-1;mt.pb(pr);
	}
	void query(){q.pb((Query){QUERY,-1,-1});mt.pb(-1);}
	void process(){ // answers all queries in order
		if(!q.size())return;
		fore(i,0,q.size())if(q[i].type==ADD&&mt[i]<0)mt[i]=q.size();
		go(0,q.size());
	}
	void go(int s, int e){
		if(s+1==e){
			if(q[s].type==QUERY){
				ll s=0,t=dsu.n-1;
				ll ans=dsu.find(s)!=dsu.find(t);
				cout<<"NY"[ans]<<"\n";
			}
			return;
		}
		int k=dsu.snap(),m=(s+e)/2;
		for(int i=e-1;i>=m;--i)if(mt[i]>=0&&mt[i]<s)dsu.join(q[i].x,q[i].y);
		go(s,m);dsu.rollback(k);
		for(int i=m-1;i>=s;--i)if(mt[i]>=e)dsu.join(q[i].x,q[i].y);
		go(m,e);dsu.rollback(k);
	}
};

const ll INF=1e18;
ll ceil(ll a, ll b){
	ll sgn=(a*b<0);
	a=abs(a),b=abs(b);
	if(sgn)return -a/b;
	return (a+b-1)/b;
}
ll floor(ll a, ll b){
	ll sgn=(a*b<0);
	a=abs(a),b=abs(b);
	if(sgn)return -(a+b-1)/b;
	return a/b;
}
ll C;
const ll MAXN=1005;
ii a[MAXN];
ii get_ran(ll i, ll j){ // integer range [,) where f(j)-f(i) >=C
	ll c=a[j].fst-a[i].fst-C;
	ll m=a[j].snd-a[i].snd;
	ll l=-INF,r=INF;
	assert(m);
	if(m>0)l=ceil(-c,m);
	else r=floor(c,-m)+1;
	return {l,r};
}
int main(){FIN;
	ll n,L; cin>>n>>C>>L;
	fore(i,1,n+1)cin>>a[i].fst>>a[i].snd;
	a[0]={0,0};
	a[n+1]={L,0};
	n+=2;
	vector<array<ll,4>> ev; // t, ty, u, v
	enum {REM,ADD,QUERY};
	ll q; cin>>q;
	fore(i,0,q){
		ll t; cin>>t;
		ev.pb({t,QUERY,-1,-1});
	}
	fore(u,0,n)fore(v,u+1,n){
		if(a[u].snd==a[v].snd){
			if(abs(a[u].fst-a[v].fst)<C){
				ev.pb({0,ADD,u,v}); // always
				// cerr<<"always "<<u<<" "<<v<<"\n";
			}
			continue;
		}
		auto [l1,r1]=get_ran(u,v);
		auto [l2,r2]=get_ran(v,u);
		// if(r-l<=0)continue;
		if(l1>l2)swap(l1,l2),swap(r1,r2);
		assert(l1==-INF&&r2==INF);
		ll s=r1,e=l2; // complement, range where |f(i)-f(j)|<C
		if(e-s<=0)continue;
		// cerr<<u<<","<<v<<": "<<s<<","<<e<<"\n";
		ev.pb({s,ADD,u,v});
		ev.pb({e,REM,u,v});
	}
	sort(ALL(ev));
	DynCon dc(n);
	for(auto [t,ty,u,v]:ev){
		if(ty==REM)dc.remove(u,v);
		else if(ty==ADD)dc.add(u,v);
		else dc.query();
	}
	dc.process();
	return 0;
}
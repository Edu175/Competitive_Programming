#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

struct UnionFind{
	int n,comp; 
	vector<int> uf,si,c;
	UnionFind(int n=0): n(n),comp(n),uf(n),si(n,1){
		fore(i,0,n)uf[i]=i;
	}
	int find(int x){return x==uf[x]?x:find(uf[x]);}
	bool join(int x, int y){
		if((x=find(x))==(y=find(y)))return false;
		if(si[x]<si[y])swap(x,y);
		si[x]+=si[y]; uf[y]=x; comp--; c.pb(y);
		return true;
	}
	int snap(){return c.size();}
	void rollback(int snap){
		while(SZ(c)>snap){
			int x=c.back(); c.pop_back(); si[uf[x]]-=si[x]; uf[x]=x; comp++;
		}
	}
};

enum {ADD,DEL,QUERY};
struct Query{int type,x,y,id=-1;};
struct DynCon{
	vector<Query> q; UnionFind dsu; vector<int> mt,rts;
	map<pair<int,int>,int> last;
	DynCon(int n): dsu(n){}
	void add(int x, int y){
		if(x>y) swap(x,y);
		q.pb((Query){ADD,x,y}); mt.pb(-1); last[{x,y}]=SZ(q)-1;
	}
	void remove(int x, int y){
		if(x>y) swap(x,y);
		q.pb((Query){DEL,x,y});
		int pr=last[{x,y}]; mt[pr]=SZ(q)-1; mt.pb(pr);
	}
	void query(int x, int y){
		if(x>y) swap(x,y);
		q.pb((Query){QUERY,x,y,SZ(rts)}); mt.pb(-1);
		rts.pb(0);
	}
	void process(){
		if(!SZ(q)) return;
		fore(i,0,SZ(q)) if(q[i].type==ADD&&mt[i]<0)mt[i]=SZ(q);
		go(0,SZ(q));
	}
	void go(int s, int e){
		if(s+1==e){
			if(q[s].type==QUERY) rts[q[s].id]=(dsu.find(q[s].x)==dsu.find(q[s].y));
			return;
		}
		int k=dsu.snap(),m=(s+e)>>1;
		for(int i=e-1; i>=m; --i)if(mt[i]>=0&&mt[i]<s)dsu.join(q[i].x,q[i].y);
		go(s,m); dsu.rollback(k);
		for(int i=m-1; i>=s; --i)if(mt[i]>=e)dsu.join(q[i].x,q[i].y);
		go(m,e); dsu.rollback(k);
	}
};

const ll maxn=1e5+5,maxsz=1e6+5;
vv bu[maxsz];

const string ans[3]={"any\n","at least one\n","none\n"};
int main(){
	JET
	ll n,m;cin>>n>>m;
	vector<ii> ar; vv W;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		ar.pb({u,v}); W.pb(w);
		bu[w].pb(i);
	}
	DynCon D(n);
	fore(i,0,maxsz){
		for(auto j: bu[i]) D.query(ar[j].fst,ar[j].snd);
		for(auto j:bu[i]) D.add(ar[j].fst,ar[j].snd);
		for(auto j:bu[i]){
			D.remove(ar[j].fst,ar[j].snd);
			D.query(ar[j].fst,ar[j].snd);
			D.add(ar[j].fst,ar[j].snd);
		}
	}
	D.process();
	vv rta(m,0);
	ll it=0;
	fore(i,0,maxsz){
		for(auto j:bu[i]) rta[j]+=D.rts[it++];
		for(auto j:bu[i]) rta[j]+=D.rts[it++];
	}
	fore(i,0,m){
		cout<<ans[rta[i]];
	}
	return 0;
}
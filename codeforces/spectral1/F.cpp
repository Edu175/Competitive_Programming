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
	int n,comp,po;
	vector<int> uf,si;
	vv rep;
	vector<ii> ads;
	vector<ii>c;
	UnionFind(int n, vv rep):n(n),comp(n),po(0),uf(n),si(n,1),rep(rep){
		fore(i,0,n)uf[i]=i;}
	int find(int x){return x==uf[x]?x:find(uf[x]);}
	bool join(int x, int y){
		if((x=find(x))==(y=find(y)))return false; // find
		if(si[x]<si[y])swap(x,y);
		
		ads.pb({rep[x],rep[y]});
		
		c.pb({y,rep[x]});
		si[x]+=si[y];uf[y]=x;comp--;
		rep[x]=max(rep[x],rep[y]);
		return true;
	}
	int snap(){return c.size();}
	void rollback(int snap){
		while(c.size()>snap){
			auto [y,r]=c.back();c.pop_back(); ads.pop_back();
			po=min(po,SZ(ads));
			rep[uf[y]]=r;
			si[uf[y]]-=si[y];uf[y]=y;comp++;
		}
	}
};
enum {ADD,DEL,QUERY};
struct Query {int type,x,y;};
struct DynCon {
	vector<Query> q;
	UnionFind dsu,glo;
	vector<int> mt;
	map<pair<int,int>,int> last;
	DynCon(int n, int k, vv rep):dsu(n,rep),glo(k,vv(k,-1)){}
	void add(int x, int y){
		if(x>y)swap(x,y);
		q.pb((Query){ADD,x,y});mt.pb(-1);last[{x,y}]=q.size()-1;
	}
	void remove(int x, int y){
		if(x>y)swap(x,y);
		q.pb((Query){DEL,x,y});
		int pr=last[{x,y}];mt[pr]=q.size()-1;mt.pb(pr);
	}
	void query(ll t){q.pb((Query){QUERY,-1,t});mt.pb(-1);}
	void process(){ // answers all queries in order
		if(!q.size())return;
		fore(i,0,q.size())if(q[i].type==ADD&&mt[i]<0)mt[i]=q.size();
		go(0,q.size());
	}
	ll res=0,cant=0;
	void go(int s, int e){
		if(s+1==e){
			if(q[s].type==QUERY) // answer query using DSU
			{
				ll tim=q[s].y;
				// cerr<<"query "<<tim<<":\n";
				fore(i,dsu.po,SZ(dsu.ads)){
					auto [u,v]=dsu.ads[i];
					// cerr<<u<<","<<v<<"\n";
					if(u!=-1&&v!=-1&&glo.join(u,v)){
						// cerr<<"joined\n";
						res+=tim,cant++;
					}
				}
				dsu.po=SZ(dsu.ads);
				// dsu.ads.clear();
			}
			return;
		}
		int k=dsu.snap(),m=(s+e)/2;
		for(int i=e-1;i>=m;--i)if(mt[i]>=0&&mt[i]<s){
			dsu.join(q[i].x,q[i].y);
		}
		go(s,m);dsu.rollback(k);
		for(int i=m-1;i>=s;--i)if(mt[i]>=e){
			dsu.join(q[i].x,q[i].y);
		}
		go(m,e);dsu.rollback(k);
	}
};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,q; cin>>n>>m>>q;
		vector<array<ll,3>> ed;
		fore(i,0,m){
			ll w,u,v; cin>>u>>v>>w;
			u--,v--;
			if(u>v)swap(u,v);
			if(u!=v)ed.pb({w,u,v});
		}
		auto _ed=ed; ed.clear();
		sort(ALL(_ed)); reverse(ALL(_ed));
		set<ii> st;
		for(auto [w,u,v]:_ed){
			if(!st.count({u,v})){
				st.insert({u,v});
				ed.pb({w,u,v});
			}
		}
		// m=SZ(ed);
		// sort(ALL(ed));
		vv spe(q);
		fore(i,0,q)cin>>spe[i],spe[i]--;
		sort(ALL(spe)); spe.resize(unique(ALL(spe))-spe.begin());
		q=SZ(spe);
		vv rep(n,-1);
		fore(i,0,q)rep[spe[i]]=i;
		vector<vector<ii>> eds(m+1);
		for(auto [w,u,v]:ed)eds[w].pb({u,v});
		DynCon dc(n,q,rep);
		fore(w,1,m+1){
			for(auto [u,v]:eds[w])dc.add(u,v);
		}
		dc.query(0);
		fore(w,1,m+1){
			for(auto [u,v]:eds[w])dc.remove(u,v);
			for(auto [u,v]:eds[w-1])dc.add(u,v);
			dc.query(w);
		}
		dc.process();
		ll res=dc.res;
		ll cant=dc.cant;
		// cerr<<q<<": "<<res<<" "<<cant<<"\n";
		if(cant!=q-1){
			res=-1;
		}
		cout<<res<<"\n";
	}
	return 0;
}

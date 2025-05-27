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
	vector<int> uf,si,dep;
	vector<ii>c;
	ll res; // # of not bridges + comp
	UnionFind(int n=0):n(n),comp(n),uf(n),si(n,1),dep(n){
		fore(i,0,n)uf[i]=i;}
	int find(int x){return x==uf[x]?x:find(uf[x]);}
	int getDep(int x){return x==uf[x]?0:dep[x]+getDep(uf[x]);}
	bool join(int x, int y){
		ll dx=getDep(x),dy=getDep(y);
		if((x=find(x))==(y=find(y))){
			ll resi=dx+dy;
			c.pb({1,resi});
			res+=resi;
			return false;
		}
		if(si[x]<si[y])swap(x,y),swap(dx,dy);
		si[x]+=si[y];uf[y]=x;comp--;
		dep[y]=dx+dy+1;
		c.pb({0,y});
		return true;
	}
	int snap(){return c.size();}
	void rollback(int snap){
		while(SZ(c)>snap){
			auto [ty,x]=c.back();c.pop_back();
			if(ty){res-=x;continue;}
			si[uf[x]]-=si[x];uf[x]=x;comp++;
			dep[x]=0; // not actually necessary because of ?0 in getDep
		}
	}
};
enum {ADD,DEL,QUERY};
struct Query {int type,x,y;};
struct DynCon {
	vector<Query> q;
	UnionFind dsu;
	vv ans;
	vector<int> mt;
	map<pair<int,int>,int> last;
	DynCon(int n):dsu(n){}
	void add(int x, int y){
		// if(x>y)swap(x,y);
		q.pb((Query){ADD,x,y});mt.pb(-1);last[{x,y}]=q.size()-1;
	}
	void remove(int x, int y){
		// if(x>y)swap(x,y);
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
				ans.pb(dsu.res);
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
int main(){FIN;
	ll n,q; cin>>n>>q;
	vv a(n);
	DynCon dc(n);
	fore(i,0,n)cin>>a[i],a[i]--,dc.add(i,a[i]);
	vector<array<ll,3>>qs(q);
	fore(i,0,q){
		ll x,y,k; cin>>x>>y>>k; x--,y--;
		qs[i]={x,y,k};
		dc.remove(x,a[x]);
		a[x]=y;
		dc.add(x,a[x]);
		dc.query();
	}
	dc.process();
	fore(i,0,q){
		auto [ksdjf,sdfjk,k]=qs[i];
		ll res=dc.ans[i]+n;
		k%=3;
		res&=1;
		if(!k){
			cout<<"0\n";
			continue;
		}
		ll ans=1;
		fore(i,0,res)ans=ans*k%3;
		cout<<ans<<"\n";
	}
	return 0;
}
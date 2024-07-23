#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(s) ((ll)s.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll C=3e5+1000,MAXV=2*C;
struct UnionFind {
	int n,comp;
	ll val=0;
	vector<ll>rs,cs;
	vector<int> uf,si,c;
	UnionFind(int n=0):n(n),comp(n),uf(n),si(n,1),rs(n,0),cs(n,0){
		fore(i,0,n){
			uf[i]=i;
			if(i>=C)cs[i]=1;
			else rs[i]=1;
		}
	}
	int find(int x){return x==uf[x]?x:find(uf[x]);}
	bool join(int x, int y){
		if((x=find(x))==(y=find(y)))return false;
		if(si[x]<si[y])swap(x,y);
		val-=rs[x]*cs[x]+rs[y]*cs[y];
		rs[x]+=rs[y],cs[x]+=cs[y];
		val+=rs[x]*cs[x];
		si[x]+=si[y];uf[y]=x;comp--;c.pb(y);
		return true;
	}
	int snap(){return c.size();}
	void rollback(int snap){
		while(c.size()>snap){
			int x=c.back();c.pop_back();
			ll p=uf[x];
			val-=rs[p]*cs[p];
			rs[p]-=rs[x]; cs[p]-=cs[x];
			val+=rs[p]*cs[p]+rs[x]*cs[x];
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
	vector<ll>ans;
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
			if(q[s].type==QUERY) // answer query using DSU
				ans.pb(dsu.val);
			return;
		}
		int k=dsu.snap(),m=(s+e)/2;
		for(int i=e-1;i>=m;--i)if(mt[i]>=0&&mt[i]<s)dsu.join(q[i].x,q[i].y);
		go(s,m);dsu.rollback(k);
		for(int i=m-1;i>=s;--i)if(mt[i]>=e)dsu.join(q[i].x,q[i].y);
		go(m,e);dsu.rollback(k);
	}
};

int main(){
	JET
	ll q; cin>>q;
	set<ii>st;
	DynCon dc(MAXV);
	while(q--){
		ll x,y; cin>>x>>y; x--; y+=C-1;
		if(st.count({x,y})){
			st.erase({x,y});
			dc.remove(x,y);
		}
		else {
			st.insert({x,y});
			dc.add(x,y);
		}
		dc.query();
	}
	dc.process();
	for(auto i:dc.ans)cout<<i<<" ";
	cout<<"\n";
	return 0;
}
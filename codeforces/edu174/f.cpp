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
		while(c.size()>snap){
			int x=c.back();c.pop_back();
			si[uf[x]]-=si[x];uf[x]=x;comp++;
		}
	}
};
enum {ADD,DEL,QUERY};
struct Query {int type,x,y;};
vv ans;
// da como que no admite aristas repetidas
struct DynCon {
	vector<Query> q;
	UnionFind dsu;
	vector<int> mt;
	// map<pair<int,int>,int> last;
	map<int,int>last;
	DynCon(int n):dsu(n){}
	void add(int x, int y, int i){
		if(x>y)swap(x,y);
		q.pb((Query){ADD,x,y});mt.pb(-1);last[i]=q.size()-1;
	}
	void remove(int x, int y, int i){
		if(x>y)swap(x,y);
		q.pb((Query){DEL,x,y});
		int pr=last[i];mt[pr]=q.size()-1;mt.pb(pr);
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
				ans.pb(dsu.comp);
				//printf("%d\n",dsu.comp);
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
	// ll t; cin>>t;
	// while(t--){
		ll n,q; cin>>n>>q;
		DynCon AB(n),A(n);
		set<ii>sta,stb;
		map<ii,ll>mpa,mpb;
		ll cnt=1;
		while(q--){
			char ty; cin>>ty;
			ll x,y; cin>>x>>y; x--,y--;
			if(x>=y)swap(x,y);
			if(ty=='A'){
				if(sta.count({x,y})){
					sta.erase({x,y});
					ll i=mpa[{x,y}];
					AB.remove(x,y,i);
					A.remove(x,y,i);
				}
				else {
					sta.insert({x,y});
					mpa[{x,y}]=cnt;
					AB.add(x,y,cnt);
					A.add(x,y,cnt);
					cnt++;
				}
			}
			else {
				if(stb.count({x,y})){
					stb.erase({x,y});
					ll i=mpb[{x,y}];
					AB.remove(x,y,i);
				}
				else {
					stb.insert({x,y});
					mpb[{x,y}]=cnt;
					AB.add(x,y,cnt);
					cnt++;
				}
			}
			A.query();
			AB.query();
			// cout<<"PINGO"<<endl;
		}
		A.process();
		vv c;
		c=ans; ans.clear();
		AB.process();
		// imp(c)
		// imp(ans)
		// cout<<endl;
		assert(SZ(c)==SZ(ans));
		
		fore(i,0,SZ(c)){
			cout<<c[i]-ans[i]<<"\n";
		}
		
	// }
	return 0;
}

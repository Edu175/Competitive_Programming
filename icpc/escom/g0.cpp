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
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC optimize("avx2,bmi,bmi2,popcnt,lzcnt")
typedef int ll;
typedef long long LL;
// typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// ull pinga(ull x) {
// 	x += 0x9e3779b97f4a7c15;
// 	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// 	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
// 	return x ^ (x >> 31);
// }
const ll MAXV=2e5+5;
int cr[MAXV];
void cribonha(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]<0)for(LL j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
vv dame(ll n){
	set<ll>st;
	while(n>1){
		ll p=(cr[n]==-1?n:cr[n]);
		st.insert(p);
		n/=p;
	}
	vv a;
	for(auto i:st)a.pb(i);
	return a;
}
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
	vv last,cant;
	vector<int> hist;
	int dif=0,cnt=0;
	void add(int x){dif+=hist[x]++==0;}
	void remove(int x){dif-=--hist[x]==0;}
	DynCon(int n, int m):dsu(n),hist(n),last(m),cant(m){}
	vector<pair<int,int>> ans;
	void add(int x, int y, int i){
		// if(x>y)swap(x,y);
		add(x); add(y);
		auto &w=cant[i]; w++;
		if(w!=1)return;
		// cout<<"added "<<x<<" "<<y<<"\n";
		q.pb((Query){ADD,x,y});mt.pb(-1);last[i]=q.size()-1;
	}
	void remove(int x, int y, int i){
		// if(x>y)swap(x,y);
		remove(x); remove(y);
		auto &w=cant[i]; w--;
		if(w!=0)return;
		// cout<<"removed "<<x<<" "<<y<<"\n";
		q.pb((Query){DEL,x,y});
		int pr=last[i];mt[pr]=q.size()-1;mt.pb(pr);
	}
	void query(){/*cout<<"query\n";*/ans.pb({0,dif});q.pb((Query){QUERY,-1,-1});mt.pb(-1);}
	void process(){ // answers all queries in order
		if(!q.size())return;
		fore(i,0,q.size())if(q[i].type==ADD&&mt[i]<0)mt[i]=q.size();
		go(0,q.size());
	}
	void go(int s, int e){
		if(s+1==e){
			if(q[s].type==QUERY) // answer query using DSU
				ans[cnt++].fst=dsu.comp;
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
	cribonha();
	ll n; cin>>n;
	vector<vv> a(n);
	vector<vector<array<ll,3>>>ed(n);
	map<ll,ll>ps;
	ll hay=0;
	fore(i,0,n){
		ll x; cin>>x;
		a[i]=dame(x);
		hay|=SZ(a[i])>0;
		for(auto &p:a[i]){
			ll _p=p;
			if(ps.count(p))p=ps[p];
			else p=SZ(ps);
			ps[_p]=p;
		}
		// imp(a[i])
	}
	if(!hay){
		cout<<"1 1\n";
		return 0;
	}
	map<ii,ll>mp;
	fore(i,0,n){
		fore(j,0,SZ(a[i])){
			ll u=a[i][j],v=a[i][(j+1)%SZ(a[i])];
			if(u>v)swap(u,v);
			ll idx=SZ(mp);
			if(mp.count({u,v}))idx=mp[{u,v}];
			mp[{u,v}]=idx;
			ed[i].pb({u,v,idx});
		}
	}
	
	
	ii obj;
	DynCon dc(SZ(ps),SZ(mp));
	auto upd=[&](DynCon &dc, ll i, ll fg){
		if(i>=n)i-=n;
		fore(j,0,SZ(ed[i])){
			auto [u,v,idx]=ed[i][j];
			(fg?dc.add(u,v,idx):dc.remove(u,v,idx));
		}
	};
	fore(i,0,n)upd(dc,i,1);
	dc.query();
	dc.process();
	obj=dc.ans[0];
	// cout<<obj.fst<<","<<obj.snd<<"\n";
	vector<ii>rans;
	fore(i,0,n)rans.pb({i,n+i});
	ll hago=1;
	while(hago){
		// cout<<"\nLEVEL\n";
		hago=0;
		DynCon dc(SZ(ps),SZ(mp));
		dc.ans.reserve(n);
		ll p=0;
		fore(i,0,n){
			ll m=(rans[i].fst+rans[i].snd)/2;
			while(p<m)upd(dc,p++,1);
			dc.query();
			upd(dc,i,0);
		}
		dc.process();
		// fore(i,0,n){
		// 	cout<<ls[i]<<" "<<rs[i]<<": "<<(ls[i]+rs[i])/2<<": "<<dc.ans[i].fst<<","<<dc.ans[i].snd<<"\n";
		// }
		ll L=0;
		fore(i,0,n){
			auto &[l,r]=rans[i];
			ll m=(l+r)/2;
			if(dc.ans[i]==obj)r=m-1;
			else l=m+1;
			l=L=max(L,l);
		}
		ll R=2*n;
		for(ll i=n-1;i>=0;i--){
			auto &[l,r]=rans[i];
			r=R=min(R,r);
			hago|=l<=r;
		}
	}
	ll S=-1,E=n+1;
	fore(i,0,n){
		auto &[l,r]=rans[i];
		assert(r+1==l);
		ll e=l;
		if(e-i<E-S)S=i,E=e;
		// cout<<i<<": "<<e<<"\n";
	}
	if(E>n)E-=n;
	cout<<S+1<<" "<<E<<"\n";
	return 0;
}

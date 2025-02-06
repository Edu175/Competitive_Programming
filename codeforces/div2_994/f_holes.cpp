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
ll n;
struct dat{
	ll k;
	multiset<ll>ans={0};
	vv uf;
	dat(){}
	struct item{
		multiset<ll>st;
		set<ll>h;
		ll mex=0;
		item(){}
		item(ll v):st({v}){go();};
		void go(){while(st.count(mex))mex++;}
		ll get(){return SZ(h)?*h.begin():mex;}
	};
	vector<item>comp;
	void saco(item &c){if(c.get()==(1ll<<k))ans.erase(ans.find(SZ(c.st)));}
	void pongo(item &c){if(c.get()==(1ll<<k))ans.insert(SZ(c.st));}
	int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
	bool join(int x, int y){
		x=find(x); y=find(y);
		if(x==y)return false;
		if(uf[x]>uf[y])swap(x,y); // y -> x
		auto &_a=comp[x],&_b=comp[y];
		if(SZ(_a.st)+SZ(_a.h)<SZ(_b.st)+SZ(_b.h))swap(x,y);
		auto &a=comp[x],&b=comp[y];
		saco(a);
		saco(b);
		
		uf[x]+=uf[y];uf[y]=x;
		
		for(auto i:b.st)a.st.insert(i);
		a.go();
		
		vv out;
		for(auto i:a.h){
			if(i>=b.mex)break;
			if(!b.h.count(i))out.pb(i);
		}
		for(auto i:out)a.h.erase(i);
		for(auto i:b.h)if(i>=a.mex)a.h.insert(i);
		a.mex=max(a.mex,b.mex);
		b.st.clear();
		b.h.clear();
		pongo(a);
		return true;
	}
	vv cum,a;
	dat(vv &_a, ll k):uf(n),comp(n),cum(n),a(n),k(k){
		fore(i,0,n)a[i]=_a[i],cum[i]=a[i]>=(1ll<<k),uf[i]=-1;
		fore(i,0,n)if(!cum[i]){
			comp[i]={a[i]};
			pongo(comp[i]);
			if(i&&!cum[i-1])join(i-1,i);
		}
	}
	void upd(ll p, ll v){
		ll cumi=v>=(1ll<<k);
		if(cum[p]&&!cumi){
			cum[p]=cumi;
			comp[p]={v};
			pongo(comp[p]);
			if(p&&!cum[p-1])join(p-1,p);
			if(p<n-1&&!cum[p+1])join(p,p+1);
		}
		else if(!cum[p]){
			auto &c=comp[find(p)];
			saco(c);
			c.st.erase(c.st.find(a[p]));
			if(!c.st.count(a[p]))c.h.insert(a[p]);
			c.st.insert(v);
			if(c.h.count(v))c.h.erase(v);
			c.go(); // no deberia
			pongo(c);
		}
		a[p]=v;
	}
	ll get(){return *prev(ans.end());}
};

// const ll K=17;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll q; cin>>n>>q;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vector<ii>upds;
		fore(_,0,q){
			ll p,x; cin>>p>>x; p--;
			upds.pb({p,a[p]});
			a[p]+=x;
		}
		// imp(a)
		reverse(ALL(upds));
		ll K=0;
		while((1ll<<K)<n+5)K++;
		vector<dat> h(K);
		fore(k,0,K)h[k]=dat(a,k);
		vv ans(q);
		fore(i,0,q){
			auto &res=ans[i];
			fore(k,0,K)res=max(res,h[k].get());
			auto [p,v]=upds[i];
			fore(k,0,K)h[k].upd(p,v);
		}
		reverse(ALL(ans));
		for(auto i:ans)cout<<i<<"\n";
	}
	return 0;
}

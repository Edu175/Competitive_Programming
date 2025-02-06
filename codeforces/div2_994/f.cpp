#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
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
		map<ll,ll>mp;
		ll cant=0,sz=0;
		item(){}
		item(ll v):cant(1),sz(1){mp[v]=1;};
	};
	bool good(item &c){return c.cant==(1ll<<k);}
	vector<item> comp;
	void saco(item &c){
		if(good(c))ans.erase(ans.find(c.sz));
	}
	void pongo(item &c){
		if(good(c))ans.insert(c.sz);
	}
	int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
	bool join(int x, int y){
		
		x=find(x); y=find(y);
		assert(x!=y);
		auto &a=comp[x],&b=comp[y];
		if(SZ(a.mp)<SZ(b.mp))swap(a,b),swap(uf[x],uf[y]);
		
		saco(a);
		saco(b);
		uf[x]+=uf[y]; uf[y]=x;
		
		for(auto [k,v]:b.mp){
			auto &w=a.mp[k];
			a.cant+=!w&&v;
			w+=v; a.sz+=v;
		}
		pongo(a);
		b.mp.clear();
		return true;
	}
	vv cum,a;
	dat(vv a, ll k):k(k),uf(n,-1),comp(n),cum(n),a(a){
		fore(i,0,n)cum[i]=a[i]>=(1ll<<k);
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
			if(!(--c.mp[a[p]]))c.cant--;
			if(!(c.mp[v]++))c.cant++;
			pongo(c);
		}
		a[p]=v;
	}
	ll get(){
		return *prev(ans.end());}
};

const ll K=17;

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
		// ll K=0;
		// while((1ll<<K)<n+5)K++;
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

#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto gdhd:v)cout<<gdhd<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5,MAXW=MAXN;
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

int main(){JET
	ll n,m; cin>>n>>m;
	vector<ll>us,vs,ws;
	vector<ii> ed[MAXW];
	vector<pair<ll,ii>> qs[MAXW];
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		ed[w].pb({u,v});
		ws.pb(w);us.pb(u);vs.pb(v);
	}
	ll q; cin>>q;
	vector<ll>ans(q,1);
	fore(_,0,q){
		ll k; cin>>k;
		fore(__,0,k){
			ll i; cin>>i; i--;
			qs[ws[i]].pb({_,{us[i],vs[i]}});
		}
	}
	UnionFind uf(n);
	fore(t,0,MAXW){
		// cout<<t<<": ";
		// fore(i,0,n)cout<<uf_find(i)<<" ";;cout<<"\n";
		auto &v=qs[t];
		sort(ALL(v));
		ll tim=uf.snap(),flag=1;
		fore(i,0,SZ(v)){
			flag&=uf.join(v[i].snd.fst,v[i].snd.snd);
			if(i==SZ(v)-1||v[i].fst!=v[i+1].fst){
				auto [idx,pa]=v[i];
				ans[idx]&=flag;
				flag=1;
				uf.rollback(tim);
			}
		}
		for(auto [u,v]:ed[t]){
			uf.join(u,v);
		}
	}
	fore(i,0,q){
		if(ans[i])cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
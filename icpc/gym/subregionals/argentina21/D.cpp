#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
#define showp(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=5e5+5;

struct UF{
	int uf[MAXN],col[MAXN];
	void init(){mset(uf,-1);mset(col,0);}
	ii find(int x){
		if(uf[x]<0)return {x,0};
		auto [p,d]=find(uf[x]);
		col[x]^=d; uf[x]=p;
		return {uf[x],col[x]};
	}
	bool join(int x, int y){
		auto [px,dx]=find(x);
		auto [py,dy]=find(y);
		// cerr<<"join "<<x<<","<<y<<": "<<px<<","<<py<<": "<<dx<<","<<dy<<"\n";
		x=px,y=py;
		if(x==y)return dx!=dy;
		if(uf[x]>uf[y])swap(x,y),swap(dx,dy); // y -> x
		uf[x]+=uf[y];uf[y]=x,col[y]=dx^dy^1;
		// cerr<<x<<","<<y<<": "<<col[x]<<","<<col[y]<<"\n";
		return 1;
	}
	bool same(int x, int y){ // can be same color
		auto [px,dx]=find(x);
		auto [py,dy]=find(y);
		x=px,y=py;
		if(x==y)return dx==dy;
		return 1;
	}
};

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<array<ll,3>> ed(m);
	fore(i,0,m){
		ll w,u,v; cin>>u>>v>>w; u--,v--;
		ed[i]={w,u,v};
	}
	sort(ALL(ed)); reverse(ALL(ed));
	UF uf; uf.init();
	vv ws;
	vector<vector<ii>> bus;
	vector<ii> tmp;
	fore(i,0,m){
		auto [w,u,v]=ed[i];
		tmp.pb({u,v});
		if(i==m-1||ed[i][0]!=ed[i+1][0]){
			bus.pb(tmp);
			ws.pb(w);
			tmp.clear();
		}
	}
	
	vv res;
	ll bad=-1;
	vv cnt(2*n);
	fore(i,0,SZ(bus))if(bad==-1){
		auto bu=bus[i];
		ll w=ws[i];
		vector<ii> a;
		for(auto [u,v]:bu)if(uf.same(u,v)){
			auto [pu,du]=uf.find(u);
			auto [pv,dv]=uf.find(v);
			u=2*pu+du;
			v=2*pv+dv;
			if(u>v)swap(u,v);
			a.pb({u,v});
		}
		sort(ALL(a)); a.resize(unique(ALL(a))-a.begin());
		for(auto& [u,v]:a){
			cnt[u]++;
			if(u!=v)cnt[v]++;
		}
		// cerr<<"\nde "<<w<<":\n";
		// showp(bu)
		// showp(a)
		// show(cnt)
		ll good=0;
		for(auto [u,v]:a){
			ll cant=cnt[u]-1;
			if(u!=v)cant+=cnt[v]-1;
			// cerr<<u<<","<<v<<" "<<cant<<"\n";
			assert(cant<=SZ(a)-1);
			if(cant<SZ(a)-1)good=1;
		}
		if(good)res.pb(w);
		for(auto& [u,v]:a)cnt[u]=cnt[v]=0;
		for(auto [u,v]:bu)if(!uf.join(u,v))bad=w;
	}
	if(0>=bad)res.pb(0);
	reverse(ALL(res));
	
	if(!SZ(res)){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	for(auto w:res)cout<<w<<"\n";
	return 0;
}

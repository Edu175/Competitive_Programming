#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet; i++)
#define snd second
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
void tle(bool b){
	if(!b){
		ll start=clock();
		while(clock()-start < 5 * CLOCKS_PER_SEC);
	}
}

const ll MAXN = 1e5+100,MAXM=2*MAXN;
int uf[MAXN];
ll n;
vector<array<ll,4>> es;
void uf_init(){
	fore(i,0,n) uf[i] = -1;
	es.clear();
}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x= uf_find(x); y = uf_find(y);
	if(x==y) return false;
	if(uf[x] > uf[y]) swap(x,y);
	uf[x] += uf[y];uf[y]=x;
	return true;
}

ll ele[MAXM];
bool kruskal(ll k, ll allow){
	sort(ALL(es));
	ll cnt=0;
	vv deg(n);
	ll uso=0;
	for(auto [w,i,x,y]:es){
		ll fg=w==1||w==2;
		ele[i]=0;
		if(!allow&&fg&&cnt==k)continue;
		if(!allow&&(deg[x]==n/2||deg[y]==n/2))continue;
		ele[i]=uf_join(x,y);
		if(ele[i]){
			deg[x]++,deg[y]++;
			cnt+=fg;
			uso++;
		}
	}
	ll fg=uso==n-1;
	fore(i,0,n)fg&=allow||deg[i]<=n/2;
	return fg;
}

bool ex(ll a, ii ar){
	return a==ar.fst||a==ar.snd;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll m; cin>>n>>m;
		uf_init();
		set<ii>st;
		fore(i,0,m){
			ll x,y; cin>>x>>y;
			x--,y--;
			if(x>y) swap(x,y);
			if(x!=y)st.insert({x,y});
		}
		vector<ii> ed(ALL(st));
		m=SZ(ed);
		// cerr<<"aristas\n";
		fore(i,0,m){
			auto [x,y]=ed[i];
			es.pb({0,i,x,y});
			// cerr<<x+1<<" "<<y+1<<"\n";
		}
		// cerr<<"end aristas\n";
		assert(kruskal(MAXN,1));
		vv deg(n);
		// cerr<<"ele\n";
		fore(i,0,m)if(ele[i]){
			auto [x,y]=ed[i];
			deg[x]++,deg[y]++;
			// cerr<<x+1<<" "<<y+1<<"\n";
		}
		// cerr<<"end ele\n";
		ll bad=0;
		vv srt;
		fore(i,0,n){
			srt.pb(deg[i]);
			if(deg[i]>deg[bad])bad=i;
		}
		sort(ALL(srt));
		reverse(ALL(srt));
		// auto isbad0=[&](ll x){return };
		// cerr<<"bad "<<bad+1<<"\n";
		ll k=deg[bad]-n/2;
		if(k>0){
			// cerr<<" tengo que arreglar "<<k<<"\n";
			vv casi(n);
			fore(i,0,m)if(ele[i]){
				auto ar=ed[i];
				auto [x,y]=ar;
				if(ex(bad,ar))casi[x]=casi[y]=1;
			}
			casi[bad]=0;
			// fore(i,0,n)cerr<<i+1<<": "<<casi[i]<<"\n";
			uf_init();
			fore(i,0,m){
				auto ar=ed[i];
				auto [x,y]=ar;
				ll w;
				bool Ebad=ex(bad,ar);
				bool Ecasi=casi[x]||casi[y];
				// bool Ebad0=
				// if(Ebad&&Ecasi)w=4;
				if(Ebad)w=3;
				else if(ele[i])w=0;
				else if(Ecasi)w=2;
				else w=1;
				es.pb({w,i,x,y});
			}
			if(!kruskal(k,0)){
				// for(auto [w,i,x,y]:es)cerr<<w<<" "<<x+1<<","<<y+1<<"\n";
				cout<<"No\n";
				continue;
			}
		}
		cout<<"Yes\n";
		fore(i,0,m)if(ele[i]){
			auto [x,y]=ed[i];
			cout<<x+1<<" "<<y+1<<"\n";
		}
	}
	
	return 0;
}

#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int K = 18;
const int maxn = 1<<K;
ll f[K][maxn], D[maxn], bus[K][maxn];
ll n;
vector<ii> paths;

struct FT{
	vv s;
	FT(int n):s(n){}
	void update(int pos, ll dif){
		for(;pos<SZ(s);pos|=pos+1)s[pos]+=dif;
	}	
	ll query(int pos){
		ll res = 0;
		for(;pos>0;pos&=pos-1)res+=s[pos-1];
		return res;
	}
};

struct FT2{
	vector<vv> ys; vector<FT> ft;
	FT2(int limx) : ys(limx){}
	void fakeUpdate(int x, int y){
		// cerr<<"fakeUpdate "<<x<<","<<y<<"\n";
		for(;x<SZ(ys);x|=x+1) ys[x].pb(y);
	}
	void init(){
		for(vv &  v : ys)sort(ALL(v)), ft.emplace_back(SZ(v));
	}
	int ind (int x, int y){
		return (int)(lower_bound(ALL(ys[x]),y) - ys[x].begin());
	}
	void update(int x, int y, ll dif){
		// cerr<<"update "<<x<<","<<y<<"\n";
		for(;x<SZ(ys);x|=x+1) ft[x].update(ind(x,y),dif);
	}
	ll query(int x, int y){
		ll sum = 0;
		for(;x;x&=x-1)sum+=ft[x-1].query(ind(x-1,y));
		return sum;
	}
	ll query(int x0, int x1, int y0, int y1){
		return query(x1,y1)-query(x0,y1)-query(x1,y0)+query(x0,y0);
	}
};

void init_lca(){
	fore(k,1,K)fore(i,0,n){
		if(f[k-1][i] >= 0)f[k][i] = f[k-1][f[k-1][i]];
	}
}

void init_bus(){
	fore(k,1,K)fore(i,0,n){
		if(bus[k-1][i] >= 0){
			bus[k][i] = bus[k-1][bus[k-1][i]];
		}
	}
}

ll lca(ll x, ll y){
	if(D[x] < D[y])swap(x,y);
	for(ll k = K-1;k>=0;k--){
		if(f[k][x] != -1 && D[f[k][x]] >= D[y])x=f[k][x];
	}
	if(x == y) return x;
	for(ll k = K-1;k>=0;k--){
		if(f[k][x] != -1 && f[k][x]!=f[k][y]){
			x = f[k][x];
			y = f[k][y];
		}
	}
	return f[0][x];
}

ii get_bus(ll x, ll y){
	if(x == y) return {x,0};
	ll res = 0;
	for(ll k = K-1;k>=0;k--){
		if(bus[k][x] != -1 && D[bus[k][x]] > D[y]){
			x = bus[k][x];
			res += (1<<k);
		}
	}
	return {x,res};
}


void process(int x, int s){
	while(x != s && bus[0][x] == -1){
		bus[0][x] = s;
		x = f[0][x];
	}	
}


vv g[maxn];
ll cnt=0,S[maxn],E[maxn];
void dfs0(ll x){
	S[x]=cnt++;
	for(auto y:g[x])dfs0(y);
	E[x]=cnt;
}

int main(){
	JET
	cin>>n;
	mset(f,-1); mset(bus,-1);
	D[0] = 0;
	fore(i,1,n){
		ll x; cin>>x;x--;
		f[0][i] = x;
		g[x].pb(i);
		D[i] = D[x]+1;
	}	
	init_lca();
	dfs0(0);
	vector<ii> all;
	ll m; cin>>m;
	while(m--){
		ll x,y; cin>>x>>y;x--,y--;
		ll p = lca(x,y);
		paths.pb({p,x}),paths.pb({p,y}); 
		all.pb({x,y});
	}
	FT2 ft(n);
	for(auto [a,b]:all)fore(_,0,2){
		ft.fakeUpdate(S[a],S[b]);
		swap(a,b);
	}
	ft.init();
	for(auto [a,b]:all)fore(_,0,2){
		ft.update(S[a],S[b],1);
		swap(a,b);
	}
	auto edu_query=[&](ll x, ll y){
		return ft.query(S[x],E[x],S[y],E[y])>0;
	};
	
	sort(ALL(paths),[&](ii a, ii b){return D[a.fst] < D[b.fst];});
	for(auto [e,s] : paths)process(s,e);
	init_bus();
	ll q; cin>>q;
	while(q--){
		ll x,y; cin>>x>>y;x--,y--;
		ll p = lca(x,y);
		auto [nx,cntx] = get_bus(x,p);
		auto [ny,cnty] = get_bus(y,p);
		if(x == p){
			if(bus[0][ny] == -1) cout<<-1<<"\n";
			else cout<<cnty+1<<"\n";
			continue;
		}
		if(y == p){
			if(bus[0][nx] == -1) cout<<-1<<"\n";
			else cout<<cntx+1<<"\n";
			continue;
		}
		if(bus[0][nx] == -1 || bus[0][ny] == -1){
			cout<<-1<<"\n";
			continue;
		}
		ll res = cntx+cnty+2-edu_query(nx,ny);
		cout<<res<<"\n";
		
	}
	return 0;
}

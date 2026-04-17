#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(X) ((ll)X.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;

vector<ii> g[MAXN];

ll n;
vv dijkstra(ll s){
	vv d(n,-1);
	d[s]=0;
	priority_queue<ii>pq;
	pq.push({0,s});
	while(SZ(pq)){
		auto [dis,x]=pq.top(); pq.pop(); dis=-dis;
		if(d[x]!=dis)continue;
		for(auto [y,w]:g[x]){
			ll nd=dis+w;
			if(d[y]==-1||nd<d[y]){
				d[y]=nd;
				pq.push({-nd,y});
			}
		}
	}
	return d;
}

const ll INF=1e4*MAXN*10;

#define oper min
#define NEUT INF
struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){
    JE
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w;
		// u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	vv xs=dijkstra(0);
	vv ys=dijkstra(1);
	vv zs=dijkstra(2);
	
	map<array<ll,3>,ll> mp;
	
	fore(i,0,n)mp[{xs[i],ys[i],zs[i]}]++;
	
	vector<array<ll,5>>vec;
	ll cnt=0;
	for(auto [fst,q]:mp){
		auto [x,y,z]=fst;
		vec.pb({z,x,y,cnt++,q});
		// cout<<x<<" "<<y<<" "<<z<<" "<<q<<"\n";
	}
	
	sort(ALL(vec));
	
	STree st(SZ(vec));
	
	ll bad=0;
	for(auto [z,x,y,pos,q]:vec){
		// cout<<x<<" "<<y<<" "<<z<<" "<<q<<": ";
		
		if(st.query(0,pos)<=y){
			bad+=q;
			// cout<<"bad";
		}
		else st.upd(pos,y);
		// cout<<"\n";
	}
	
	cout<<n-bad<<"\n";
	
    return 0;
}
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
const ll MAXN=1e5+5,INF=1e18;

ll ans[MAXN];

struct node{
	ll sum=0;
	vv nod;
	priority_queue<ii> qs;
	node(){}
	node(ll i, ll v):sum(v),nod(1,i){}
	ll sz(){return SZ(qs)+SZ(nod);}
	void answer(ll r){
		while(SZ(qs)&&-qs.top().fst<r){
			auto [v,i]=qs.top(); v=-v;
			// cout<<"ans "<<i<<": "<<sum<<"\n";
			ans[i]=sum+v;
			qs.pop();
		}
	}
	void merge(node &rhs){
		sum+=rhs.sum;
		for(auto i:rhs.nod)nod.pb(i);
		rhs.nod.clear();
		while(SZ(rhs.qs))qs.push(rhs.qs.top()),rhs.qs.pop();
	}
};

ll id[MAXN];
node comp[MAXN];

void merge(ll x, ll y){
	x=id[x]; y=id[y];
	if(x==y)return;
	if(comp[x].sz()<comp[y].sz())swap(x,y);
	for(auto i:comp[y].nod)id[i]=x;
	comp[x].merge(comp[y]);
}

int main(){FIN;
	ll n,m,q; cin>>n>>m>>q;
	vv a(n);
	fore(i,0,n){
		cin>>a[i];
		id[i]=i;
		comp[i]=node(i,a[i]);
	}
	vector<array<ll,3>> ed;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		ed.pb({w,u,v});
	}
	sort(ALL(ed));
	fore(i,0,q){
		ll x,k; cin>>x>>k; x--;
		comp[x].qs.push({-k,i});
	}
	for(auto [w,x,y]:ed){
		// cout<<"edge "<<w<<": "<<x<<" "<<y<<"\n";
		auto &L=comp[id[x]], &R=comp[id[y]];
		L.answer(w-L.sum);
		R.answer(w-R.sum);
		merge(x,y);
	}
	comp[id[0]].answer(INF);
	fore(i,0,q)cout<<ans[i]<<"\n";
	return 0;
}

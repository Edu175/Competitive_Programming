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
const ll MAXN=2e5+5;

ll id[MAXN];
set<ll> comp[MAXN];
ll n;
void uf_init(){fore(i,0,n)id[i]=i,comp[i]={i};}
ll cant;
void join(ll x, ll y){
	x=id[x],y=id[y];
	assert(x!=y);
	if(SZ(comp[x])<SZ(comp[y]))swap(x,y);
	for(auto i:comp[y]){
		ll j1=(i+1)%n;
		ll j2=(i-1+n)%n;
		cant-=comp[x].count(j1);
		cant-=j1!=j2&&comp[x].count(j2);
	}
	for(auto i:comp[y]){
		id[i]=x;
		comp[x].insert(i);
	}
	comp[y].clear();
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll w; cin>>n>>w;
		ll pus=0;
		vv fa(n);
		fore(i,1,n)cin>>fa[i],fa[i]--;
		cant=n;
		uf_init();
		
		fore(_,0,n-1){
			ll x,val; cin>>x>>val; x--;
			pus+=val;
			join(x,fa[x]);
			ll res=(w-pus)*cant+2*pus;
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

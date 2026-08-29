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
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e6+5;
int uf[MAXN];
void uf_init(ll n){fore(i,0,n)uf[i]=-1;}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
ll n;
bool uf_join(int x, int y){
	if(max(x,y)>=n)return 0;
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
vv a,sa;
bool can(ll k){ // 1<<k)
	uf_init(n);
	fore(i,0,n)fore(j,0,k){
		uf_join(i,i^(1ll<<j));
	}
	vector<vv> h(n);
	fore(i,0,n)h[uf_find(i)].pb(i);
	vv b(n);
	fore(i,0,n){
		auto ind=h[i];
		vv vals; for(auto i:ind)vals.pb(a[i]);
		sort(ALL(vals));
		fore(id,0,SZ(ind))b[ind[id]]=vals[id];
	}
	return b==sa;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n; ll q; cin>>q; assert(!q);
		a=vv(n);
		fore(i,0,n)cin>>a[i];
		sa=a; sort(ALL(sa));
		ll l=-1,r=__lg(n)+1;
		while(r-l>1){
			ll m=(l+r)/2;
			if(can(m))r=m;
			else l=m;
		}
		ll k=r-1;
		ll res=k==-1?0:(1ll<<k);
		cout<<res<<"\n";
	}
	return 0;
}

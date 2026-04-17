#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
ii NEUT={MAXN,-1};
ii st[MAXN];
ll n;
ll w[MAXN],c[MAXN]; // c is number of sinks available
// INDEXADO DESDE UNOOOOOO (1!!!!11111!)
ii chi(ll k){
	auto ans=st[k];
	ans.fst+=(w[k]>=0?1:-1);
	return ans;
}
void recalc(ll k){
	ii val=c[k]>0?ii({0,k}):NEUT;
	st[k]=min({val,chi(2*k),chi(2*k+1)});
}
void init(){
	for(ll i=n;i>0;i--)recalc(i);
}
void upd(ll k){
	for(;k>0;k>>=1)recalc(k);
}
ll lca(ll x, ll y){
	if(x==y)return x;
	if(x>y)return lca(x/2,y);
	return lca(x,y/2);
}

void upd_path(ll s, ll t){
	while(!(c[t]>0));
	ll p=lca(s,t);
	fore(b,0,2)for(ll x=(b?t:s);x!=p;x>>=1)w[x]+=(b?1:-1);
	c[t]--;
	upd(s); upd(t);
}
ii query(ll x){
	auto ans=st[x];
	ll acum=0;
	for(ll y=x;y>0;acum+=(w[y]<=0?1:-1),y>>=1)
		ans=min(ans,{st[y].fst+acum,st[y].snd});
	return ans;
}

int main(){
	JET
	fore(i,0,MAXN)st[i]=NEUT;
    #ifdef ONLINE_JUDGE
    freopen("mole.in","r",stdin);     freopen("mole.out","w",stdout);
    #endif
	ll m; cin>>n>>m;
	fore(i,1,n+1)cin>>c[i];
	init();
	ll res=0;
	while(m--){
		ll s; cin>>s;
		auto [del,t]=query(s);
		res+=del;
		upd_path(s,t);
		cout<<res<<" ";
	}
	cout<<"\n";
    return 0;
}
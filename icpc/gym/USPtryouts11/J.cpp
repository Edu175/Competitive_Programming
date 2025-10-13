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
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;
struct FTree1d{
	ll ft[MAXN+1];
	void upd(int i0, ll v){
		for(int i=i0+1;i<=MAXN;i+=i&-i)
			maxig(ft[i],v);
	}
	ll get(int i0){ // [0,i0)
		ll r=NEUT;
		for(int i=i0;i;i-=i&-i)
			maxig(r,ft[i]);
		return r;
	}
};

bool good(vv a, vv b){
	ll fg=1;
	fore(i,0,SZ(a))fg&=a[i]<b[i];
	return fg;
}
FTree1d ft1;
FTree2d ft2;

vector<vv> a;
ll m;
ll get(ll i){
	if(m==1)return ft1.get(a[i][0]);
	if(m==2)return ft2.get(a[i][0],a[i][1]);
	ll mx=NEUT;
	fore(j,0,i){
		ll cur=j;
		if(good(a[j],a[i]))maxig(mx,cur);
	}
	return mx;
}
void upd(ll i){
	if(m==1)ft1.upd(a[i][0],i);
	if(m==2)ft2.upd(a[i][0],a[i][1],i);
}

int main(){FIN;
	ll n; cin>>m>>n; n++;
	a=vector<vv>(n,vv(m));
	fore(j,0,m)fore(i,1,n)cin>>a[i][j];
	
	auto zip=[&](ll w){
		vv vals;
		fore(i,0,n)vals.pb(a[i][w]);
		sort(ALL(vals));
		vals.resize(unique(ALL(vals))-vals.begin());
		fore(i,0,n)a[i][w]=lower_bound(ALL(vals),a[i][w])-vals.begin();
	};
	
	fore(i,0,m)zip(i);
	vv fa(n);
	val=vv(n);
	// fore(i,0,MAXN+1)ft1.ft[i]=NEUT; // ya es 0
	fore(i,1,n){
		fa[i]=get(i);
		val[i]=val[fa[i]]+1;
		upd(i);
	}
	ll mx=1;
	fore(i,1,n)if(val[i]>val[mx])mx=i;
	vv res;
	while(mx!=NEUT)res.pb(mx),mx=fa[mx];
	reverse(ALL(res));
	for(auto i:res)cout<<i<<" ";;cout<<"\n";
	return 0;
}

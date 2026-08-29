#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a){for(auto x:a)cout<<a<<" ";cout<<"\n"}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
vv xs,ys;

vector<vector<ii>> st; // has (index, y)

vector<ii> sd; // by x
ll get_idx(ll t, vector<ii> &v){
	return lower_bound(ALL(v),ii({t,-1}))-v.begin();
}
void init(){ // dado xs, ys
	ll n=SZ(xs);
	fore(i,0,n)sd.pb({xs[i],i});
	sort(ALL(sd));
	st.resize(2*n+5);
	fore(t,0,n){
		ll i=sd[t].snd;
		for(ll p=t+n;p>0;p>>=1)st[p].pb({ys[i],i});
	}
	fore(k,0,2*n)sort(ALL(st[k]));
}
const ll MX=50;
vv query(ll x0, ll x1, ll y0, ll y1){
	vv ret; // indices
	ll n=SZ(xs);
	ll l=get_idx(x0,sd)+n;
	ll r=get_idx(x1,sd)+n;
	auto agr=[&](vector<ii> &v){
		ll s=get_idx(y0,v);
		ll e=get_idx(y1,v);
		fore(i,s,e){
			if(SZ(ret)>=MX)break;
			ret.pb(v[i].snd);
		}
	};
	for(;l<r;l>>=1,r>>=1){
		if(l&1)agr(st[l++]);
		if(r&1)agr(st[--r]);
	}
	return ret;
}


int main(){
	JET
	ll n,q; cin>>n>>q;
	xs=ys=vv(n);
	vv h(n);
	fore(i,0,n)cin>>xs[i]>>ys[i]>>h[i];
	init();
	while(q--){
		ll x0,y0,x1,y1; cin>>x0>>y0>>x1>>y1;
		auto v=query(x0,x1+1,y0,y1+1);
		vv hs;
		for(auto i:v)hs.pb(h[i]);
		sort(ALL(hs));
		ll good=0;
		fore(i,0,SZ(hs)-2){
			if(hs[i]+hs[i+1]>hs[i+2]){good=1;break;}
		}
		cout<<good<<"\n";
	}
	return 0;
}
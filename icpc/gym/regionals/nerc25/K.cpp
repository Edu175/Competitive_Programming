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
typedef __uint128_t mask;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
vv gest(vector<mask> x, ll n){
	ll p=-1;
	fore(i,0,n)if(!x[i])p=i;
	assert(p!=-1);
	vv ans(n); ans[p]=1;
	fore(i,0,n)if(x[i]){
		auto &res=ans[i];
		fore(j,0,i)if(x[i]>>j&1)res^=ans[j];
	}
	return ans;
}
const ll ITER=400;
mt19937 rng(175);
pair<vv,ll> cant(vector<mask> a, ll n, ll k){
	vector<mask> x(n);
	ll dim=0;
	for(auto v:a){
		for(ll i=n-1;i>=0;i--)v=min(v,v^x[i]);
		if(v){
			ll p=-1;
			fore(i,0,n)if(v>>i&1)p=i;
			x[p]=v;
			assert(p!=-1);
			dim++;
		}
	}
	if(dim<n)return {gest(x,n),0};
	ll ans=SZ(a)+5;
	
	fore(_,0,ITER){
		shuffle(ALL(a),rng);
		vector<mask> y(n);
		ll ban=rng()%n;
		ll val=0;
		for(auto v:a){
			for(ll j=n-1;j>=0;j--)v=min(v,v^y[j]);
			if(v){
				ll p=-1;
				fore(i,0,n)if(v>>i&1)p=i;
				if(p==ban){
					val++;
					if(val>=k)break;
					continue;
				}
				y[p]=v;
				assert(p!=-1);
			}
		}
		if(val<ans)ans=val,x=y;
	}
	// cerr<<"ans "<<ans<<"\n";
	return {gest(x,n),ans};
}

int main(){FIN;
	ll n,k,m; cin>>n>>k>>m;
	vector<pair<mask,ll>> a(m);
	vector<ii> rans;
	fore(i,0,m){
		ll l,r,x; cin>>l>>r>>x; l--;
		rans.pb({l,r});
		mask v=0; fore(i,l,r)v|=mask(1)<<i;
		a[i]={v,x};
	}
	vv ans(n);
	ll val=0;
	fore(j,0,30){
		vector<mask> b;
		fore(i,0,m)if(a[i].snd>>j&1)b.pb(a[i].fst);
		auto [got,c]=cant(b,n,k);
		if(k<=c)continue;
		val+=(k-c)*(1ll<<j);
		fore(i,0,n)ans[i]|=ll(got[i])<<j;
	}
	show(ans)
	ll a_or=0; for(auto i:ans)a_or|=i;
	ll sumz=0;
	fore(i,0,m){
		ll y=0; auto [l,r]=rans[i];
		ll x=a[i].snd;
		fore(j,l,r)y^=ans[j];
		ll z=y&x;
		sumz+=z;
	}
	ll deb=k*a_or-sumz;
	assert(val==deb);
	return 0;
}
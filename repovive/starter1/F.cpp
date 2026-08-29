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

ll n,c; vv _a;
const ll MAXN=2e5+5;
ll F[20][2*MAXN];
bool can(ll sum){
	auto a=_a;
	if(sum<*max_element(ALL(a)))return 0;
	for(auto i:_a)a.pb(i);
	vv to(2*n);
	ll r=0,cur=0;
	fore(i,0,2*n){
		while(r<2*n&&cur+a[r]<=sum)cur+=a[r++];
		to[i]=r;
		cur-=a[i];
	}
	ll K=__lg(2*n)+1;
	assert(K<=20);
	// vector<vv> F(K,vv(2*n+1));
	fore(i,0,2*n)F[0][i]=to[i];
	F[0][2*n]=2*n;
	fore(k,1,K)fore(i,0,2*n+1){
		F[k][i]=F[k-1][F[k-1][i]];
	}
	fore(i,0,n){
		ll x=i,e=n+i,cant=0;
		for(ll k=K-1;k>=0&&cant<=c;k--){
			ll y=F[k][x];
			if(y<e)x=y,cant+=1ll<<k;
		}
		cant++;
		if(cant<=c){
			assert(F[0][x]>=e);
			return 1;
		}
	}
	return 0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>c;
		_a=vv(n);
		fore(i,0,n)cin>>_a[i];
		ll l=0,r=accumulate(ALL(_a),0ll)+5;
		while(r-l>1){
			ll m=(l+r)/2;
			if(can(m))r=m;
			else l=m;
		}
		cout<<r<<"\n";
	}
	return 0;
}

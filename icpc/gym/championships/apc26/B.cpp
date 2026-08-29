#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto a:x)cout<<a<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll>  ii;

const ll MAXN=5e5+5;

ll tra(ii x){
	if(x.fst==x.snd)return x.fst;
	assert(!x.fst&&x.snd);
	return 2;
}

vv g[MAXN];
ll k;
ll f(ll x){
	vector<ll> got;
	for(auto y:g[x])got.pb(f(y));
	if(!SZ(got)){
		ll ret=x>=k;
		return ret;
	}
	ii ans;
	vv cant(3);
	for(auto e:got)cant[e]++;
	fore(i,0,2){
		auto &res=(!i?ans.fst:ans.snd);
		res=(cant[i]>=cant[i^1])^(!i);
	}
	return tra(ans);
}
bool wins(ll _k){
	k=_k;
	auto got=f(0);
	ll ret=got;
	if(ret==2)ret=0;
	// cerr<<"wins "<<k<<": "<<ret<<"\n";
	return ret;
}

int main(){
	JET
	ll n; cin>>n;
	fore(i,1,n){
		ll p; cin>>p; p--;
		g[p].pb(i);
	}
	ll l=-1,r=n;
	while(r-l>1){
		ll m=(l+r)/2;
		if(wins(m))l=m;
		else r=m;
	}
	ll res=l;
	cout<<res+1<<"\n";
	return 0;
}
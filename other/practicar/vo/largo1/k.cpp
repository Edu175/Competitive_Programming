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
#pragma GCC optimize("03,unroll-loops")
const ll INF=2005;

int main(){FIN;
	ll n,k; cin>>n>>k;
	if(k==1){
		cout<<"0\n";
		return 0;
	}
	// assert(k>1);
	vv a(n);
	fore(i,0,n)cin>>a[i];
	
	vv divs;
	for(ll i=1;i*i<=k;i++){
		if(k%i==0)divs.pb(i),divs.pb(k/i);
		if(i*i==k)divs.pop_back();
	}
	sort(ALL(divs));
	// imp(divs)
	auto get_idx=[&](ll v){
		ll p=lower_bound(ALL(divs),v)-divs.begin();
		assert(divs[p]==v);
		return p;
	};
	ll m=SZ(divs);
	vector<vector<ii>>dp(n+1,vector<ii>(m));
	#define f(i,d) dp[(i)][d]
	fore(j,0,m)f(n,j)=ii({INF,INF});
	f(n,get_idx(1))={0,0};
	for(ll i=n-1;i>=0;i--)fore(j,0,m){
		auto &res=f(i,j);
		res=f(i+1,j);
		ll d=divs[j];
		ll g=gcd(d,a[i]);
		auto go=f(i+1,get_idx(d/g));
		go.fst++,go.snd+=a[i];
		res=min(res,go);
	}
	vv ids;
	ll j=get_idx(k);
	if(f(0,j).fst>n){
		cout<<"-1\n";
		return 0;
	}
	fore(i,0,n){
		auto &res=f(i,j);
		if(res==f(i+1,j))continue;
		ids.pb(i);
		ll d=divs[j];
		ll g=gcd(d,a[i]);
		j=get_idx(d/g);
	}
	// if(!SZ(ids))ids.pb(0);
	cout<<SZ(ids)<<"\n";
	for(auto i:ids)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
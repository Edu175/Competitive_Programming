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
vv fib={1,2};
ll M;
vv decomp(ll x){
	vv ids;
	for(ll j=M-1;j>=0;j--){
		if(x>=fib[j])ids.pb(j),x-=fib[j],j--;
	}
	assert(!x);
	return ids;
}

vector<vv> ds;

vv oc;

bool solve(ll i, ll x){
	auto occ=oc;
	for(auto j:ds[i])occ[j]--;
	for(auto j:decomp(x-1)){
		occ[j]++;
		if(!j)return 0;
	}
	fore(i,0,M)if(occ[i]>1)return 0;
	fore(i,0,M-1)if(occ[i]==0&&occ[i+1]>0)return 0;
	// cout<<"solve "<<i<<" "<<x<<": ";
	// imp(occ)
	return 1;
}

int main(){FIN;
	while(fib.back()<1e10)fib.pb(fib.end()[-2]+fib.end()[-1]);
	M=SZ(fib);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ds=vector<vv>(n);
		fore(i,0,n)ds[i]=decomp(a[i]);
		oc=vv(M);
		fore(i,0,n)for(auto j:ds[i])oc[j]++;
		ll fg=0;
		fore(i,0,n){
			ll got=solve(i,a[i]);
			fg|=got;
			// cout<<i<<": "<<got<<"\n";
		}
		if(fg)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

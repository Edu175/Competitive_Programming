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


vv f(ll n, ll k){
	if(n==0)return {};
	// cout<<"f "<<n<<" "<<k<<"\n";
	if((n&1)==0){
		vv ans={n/2-1};
		for(ll i=n-1;i>=0;i--)fore(j,0,k-(i==n/2-1))ans.pb(i);
		return ans;
	}
	vv l(k,n/2);
	auto r=f(n-1,k);
	for(auto i:r){
		if(i>=n/2)i++;
		l.pb(i);
	}
	return l;
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	vv c(n);
	auto r=f(n,k);
	for(auto i:r)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}

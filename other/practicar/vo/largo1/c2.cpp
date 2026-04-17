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
const ll INF=1e16;

int main(){FIN;
	ll n,k; cin>>n>>k;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	auto get=[&](vv a, ll sig){
		vector<ii> b(n,{-INF,-1});
		ll s=0;
		fore(i,n-k,n)s+=a[i];
		for(ll i=n-k;i>=0;i--){
			b[i]=max(b[i+1],ii({s,sig*i}));
			if(i)s=s+a[i-1]-a[i+k-1];
		}
		return b;
	};
	auto r=get(a,-1);
	reverse(ALL(a));
	auto l=get(a,1);
	reverse(ALL(l));
	
	fore(i,0,n-1)res=max(res,l[i]+r[i+1]);
	cout<<res<<"\n";
	return 0;
}
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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXV=1e6+5;

ll cant(ll n){return n*(n+1)/2;}

int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	vv pos[MAXV];
	fore(i,0,n)cin>>a[i],pos[a[i]].pb(i);
	ll ans=0;
	fore(c,0,MAXV){
		auto &v=pos[c];
		v.insert(v.begin(),-1);
		v.pb(n);
		ll res=cant(n);
		fore(i,0,SZ(v)-1)res-=cant(v[i+1]-v[i]-1);
		ans+=res;
		// if(res)cout<<c<<": "<<res<<"\n";
	}
	// cout<<ans<<"\n";
	ans=ans*2-n;
	ld res=ld(ans)/(n*n);
	// res*=2;
	// res--;
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}

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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		vector<vv> ds(2);
		fore(i,0,n)ds[i&1].pb(b[i]-a[i]);
		ll sum=accumulate(ALL(a),0ll);
		fore(i,0,2){
			sort(ALL(ds[i]));
			reverse(ALL(ds[i]));
		}
		ll dif=0,cur=0;
		fore(i,0,min(SZ(ds[0]),SZ(ds[1]))){
			cur+=ds[0][i]+ds[1][i];
			dif=max(dif,cur);
			// cerr<<i<<": "<<cur<<"\n";
		}
		sum+=dif;
		cout<<sum<<"\n";
	}
	return 0;
}

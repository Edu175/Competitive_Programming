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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv a(n),b(m);
		fore(i,0,n)cin>>a[i];
		fore(i,0,m)cin>>b[i];
		ll kev=a[0];
		sort(ALL(a));
		ll p=upper_bound(ALL(a),kev)-a.begin();
		vv pen;
		ll sum=0;
		// cout<<kev<<" "<<p<<" kev p\n";
		// imp(a);
		fore(i,0,m){
			ll q=lower_bound(ALL(a),b[i])-a.begin();
			if(q<n&&q>=p)pen.pb(n-q),sum+=pen.back();
		}
		sort(ALL(pen));
		vv qs[m+5];
		vv ans(m+1);
		fore(k,1,m+1)qs[m%k].pb(k);
		fore(r,0,m+5){
			for(auto k:qs[r]){
				ll tot=m/k;
				ans[k]=tot;
				// imp(pen);
				// cout<<k<<" "<<tot<<": ";
				for(ll i=SZ(pen)-1;i>=0;i-=k)ans[k]+=pen[i];
				// ,cout<<pen[i]<<" ";
				// cout<<" = "<<ans[k]<<"\n";
			}
			if(SZ(pen))sum-=pen.back(),pen.pop_back();
		}
		fore(i,1,m+1)cout<<ans[i]<<" ";;cout<<"\n";
	}
	return 0;
}

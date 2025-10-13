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
		ll n,q; cin>>n>>q;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv ri(n);
		for(ll i=n-1;i>=0;i--)
		for(ri[i]=i+1;ri[i]!=n&&a[i]<=a[ri[i]];ri[i]=ri[ri[i]]);
		
		vv le(n);
		fore(i,0,n)
		for(le[i]=i-1;le[i]!=-1&&a[i]>=a[le[i]];le[i]=le[le[i]]);
		
		vector<ll> hay(n,n);
		fore(i,0,n)if(le[i]!=-1)hay[le[i]]=min(hay[le[i]],ri[i]);
		
		vector<ll> ans(q);
		vector<vector<ii>> qs(n);
		fore(i,0,q){
			ll l,r; cin>>l>>r; l--;
			qs[l].pb({r,i});
		}
		ll mn=n;
		for(ll l=n-1;l>=0;l--){
			mn=min(mn,hay[l]);
			// cerr<<mn<<": "<<
			for(auto [r,i]:qs[l])ans[i]=mn<r;
		}
		
		for(auto i:ans){
			if(i)cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
	return 0;
}

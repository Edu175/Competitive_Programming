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
		ll n,k; cin>>n>>k; k--;
		string s; cin>>s;
		ll l=k;
		while(l>=0&&s[l]=='.')l--;
		ll r=k;
		while(r<n&&s[r]=='.')r++;
		ll res0=min(1+l+1,n-k);
		ll res1=min(1+n-r,k+1);
		// cerr<<res0<<" "<<res1<<": ";
		cout<<max(res0,res1)<<"\n";
	}
	return 0;
}

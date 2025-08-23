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
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll u=0;
		string ans;
		ll l=0,r=n-1;
		for(ll i=0;i+1<n;i+=2){
			string lr="LR";
			if(a[l]>a[r])swap(lr[0],lr[1]);
			if(u)ans.pb(lr[1]),ans.pb(lr[0]),u=0;
			else ans.pb(lr[0]),ans.pb(lr[1]),u=1;
			l++,r--;
		}
		if(SZ(ans)<n)ans.pb('L');
		assert(SZ(ans)==n);
		cout<<ans<<"\n";
	}
	return 0;
}

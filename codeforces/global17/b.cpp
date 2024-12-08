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
		auto can=[&](ll x)->bool{
			// cout<<"can "<<x<<"\n";
			ll l=0,r=n-1;
			while(l<=r){
				// cout<<l<<","<<r<<"\n";
				if(a[l]==a[r])l++,r--;
				else {
					if(a[l]==x)l++;
					else if(a[r]==x)r--;
					else return 0;
				}
			}
			return 1;
		};
		vv cs;
		fore(i,0,n/2)if(a[i]!=a[n-1-i]){
			cs.pb(a[i]);
			cs.pb(a[n-1-i]);
			break;
		}
		if(!SZ(cs)||can(cs[0])||can(cs[1]))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

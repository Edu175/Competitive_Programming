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
		ll tot=n;
		vv a;
		map<ll,ll>mp;
		fore(i,0,n){
			ll x; cin>>x;
			if(!SZ(a)||a.back()!=x)a.pb(x);
			mp[x]++;
		}
		n=SZ(a);
		ll res=0;
		fore(i,0,n){
			ll s=a[i];
			ll resi=mp[s];
			ll mx=s;
			while(1){
				ll p=mx==s?i+1:lower_bound(ALL(a),2*mx-s)-a.begin();
				if(p>=n)break;
				resi++;
				mx=a[p];
			}
			res=max(res,resi);
		}
		cout<<tot-res<<"\n";
	}
	return 0;
}

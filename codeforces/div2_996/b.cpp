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
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i];
		vv neg;
		ll mn=1e9+5;
		fore(i,0,n){
			cin>>b[i];
			ll s=a[i]-b[i];
			if(s<0)neg.pb(-s);
			else mn=min(mn,s);
		}
		if(SZ(neg)==0||(SZ(neg)==1&&neg[0]<=mn))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

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
		string a,b;
		cin>>a>>b;
		vv c(2);
		fore(i,0,n)c[i&1]+=a[i]=='0';
		fore(i,0,n)c[(i&1)^1]+=b[i]=='0';
		if(c[0]>=(n+1)/2&&c[1]>=n/2)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

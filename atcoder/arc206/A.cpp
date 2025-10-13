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
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	// vv b;
	// fore(i,0,n)if(i==n-1||a[i]!=a[i+1])b.pb(a[i]);
	// swap(a,b);
	// n=SZ(a);
	ll res=1;
	map<ll,ll>mp;
	for(ll i=n-1;i>=0;i--){
		ll c=n-1-i-mp[a[i]]++;
		if(i==0||a[i]!=a[i-1])res+=c;
	}
	cout<<res<<"\n";
	return 0;
}

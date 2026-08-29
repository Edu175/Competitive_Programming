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
bool pali(ll n){
	string s=to_string(n);
	auto rs=s; reverse(ALL(rs));
	return s==rs;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a=n%12,b=n-a;
		while(a<=n&&!pali(a))a+=12,b-=12;
		if(a>n)cout<<"-1\n";
		else cout<<a<<" "<<b<<"\n";
	}
	return 0;
}

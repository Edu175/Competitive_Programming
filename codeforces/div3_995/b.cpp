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
		ll n,a,b,c; cin>>n>>a>>b>>c;
		ll k=(n+a+b+c-1)/(a+b+c)-1;
		ll d=k*(a+b+c),res=3*k;
		if(d<n)res++,d+=a;
		if(d<n)res++,d+=b;
		if(d<n)res++,d+=c;
		cout<<res<<"\n";
	}
	return 0;
}

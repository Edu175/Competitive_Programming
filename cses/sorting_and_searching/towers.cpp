#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll>v;
	for(auto x:a){
		ll p=upper_bound(ALL(v),x)-v.begin();
		if(p<SZ(v))v[p]=x;
		else v.pb(x);
	}
	cout<<SZ(v)<<"\n";
	return 0;
}

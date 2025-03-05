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
const ll MOD=998244353;

int mul(ll a, ll b){return a*b%MOD;}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		reverse(ALL(a));
		while(SZ(a)&&!a.back())a.pop_back();
		k--;
		n=SZ(a);
		ll rem=(n-1)%k;
		ll res=1;
		if(!SZ(a))res=0;
		else {
			// imp(a)
			// cerr<<rem<<" rem\n";
			fore(i,0,n-rem)res=mul(res,a[i]);
		}
		cout<<res<<"\n";
	}
	return 0;
}

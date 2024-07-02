#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define snd second
#define fst first
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
 
 int main(){JET
	#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n; cin>>n;
	vector<ll>p;
	for(ll i=2;i*i<=n;i++){
		ll c=0;
		while(n%i==0)c++,n/=i;
		if(c)p.pb(c);
	}
	if(n>1)p.pb(1);
	if(p==vv({1,1,1}))cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
 }
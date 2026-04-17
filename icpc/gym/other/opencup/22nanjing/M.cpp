#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET 
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n == 1){
			ll x; cin>>x; cout<<x<<"\n";
			continue;
		}
		bool pos = false, neg = false;
		ll sum=0, mini = 1e10, maxi = -1e10;
		fore(i,0,n){
			ll x;  cin>>x;
			sum+=abs(x), mini = min(mini,x), maxi = max(maxi,x);
			if(x>=0) pos = true;
			if(x<0) neg =  true;
		}
		if(pos && !neg) cout<<sum - 2*mini<<"\n";
		else if(pos && neg) cout<<sum<<"\n";
		else cout<<2 * maxi + sum<<"\n";
	}
	
	return 0;
}
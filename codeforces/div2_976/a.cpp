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
		ll n,k; cin>>n>>k;
		if(k==1){
			cout<<n<<"\n";
			continue;
		}
		vector<ll>pot;
		ll p=1;
		while(p<=n)pot.pb(p),p*=k;
		ll res=0,j=SZ(pot)-1;
		while(n){
			while(pot[j]>n)j--;
			ll q=n/pot[j];
			n-=q*pot[j];
			res+=q;
		}
		cout<<res<<"\n";
	}
	return 0;
}

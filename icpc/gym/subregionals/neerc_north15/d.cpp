#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define bint __int128
const ll D=60,T=38;

int main(){FIN
	#ifdef ONLINE_JUDGE
	freopen("distribution.in","r",stdin);     freopen("distribution.out","w",stdout);
	#endif
	ll pot[T]; pot[0]=1;
	fore(i,1,T)pot[i]=pot[i-1]*3;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>res;
		fore(i,0,D){
			if(n==0)break;
			assert(n%(1ll<<i)==0); //dpsifhh
			ll p=-1,u=T;
			for(ll j=u-1;j>=0;j--){
				bint x=bint(1ll<<i)*bint(pot[j]);
				if(x<=n&&(n-x)%(1ll<<(i+1))==0){
					res.pb(x);
					n-=x;
					u=j;
					break;
				}
			}
		}
		assert(n==0);
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	return 0;
}
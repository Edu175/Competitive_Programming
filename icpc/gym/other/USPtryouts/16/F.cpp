#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll).x.size())
#define ALL(x) x.begin(),x.end()
#define fore(i,a,b) for(ll i=a,aei=b;i<aei;++i)
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define imp(v) for(auto messi:v) cout << messi << " ";cout << "\n";
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,p; cin>>n>>p; p--;
		ll b=0,res=0;
		while(n>0){
			if(p%2==b){
				res+=p/2;
				break;
			}
			if(!b){
				res+=(n+1)/2,b^=(n%2),p/=2,n=n/2;
			}
			else {
				res+=n/2,b^=(n%2),p/=2,n=(n+1)/2;
			}
		}
		res++;
		cout<<res<<"\n";
	}
	return 0;
}

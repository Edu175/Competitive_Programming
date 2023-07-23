#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		int a,b; cin>>a>>b;
		cout<<gcd(a,b)<<"\n";
		cout<<__gcd(a,b)<<"\n";
	}
	//cout<<__builtin_clz(n)<<"\n";
	/*ll c=0,l=1;
	fore(i,1,1e7){
		ll x=i,d=0;
		for(ll j=2;j*j<=x;j++){
			if(x%j==0){
				while(x%j==0)x/=j,d++;
				break;
			}
		}
		if(x==1||d==0)c++,l=i;
		if(c>=3e5)break;
	}
	cout<<c<<" "<<l<<"\n";*/
	return 0;
}

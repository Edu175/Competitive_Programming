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
		ll n,m; cin>>n>>m;
		n%=m;
		if(n==0){
			cout<<"0\n";
			continue;
		}
		/*if(__builtin_popcountll(m)!=1){
			cout<<"-1\n";
			continue;
		}*/
		ll k=63-__builtin_clzll(m);
		ll res=0;
		ll _n=n;
		for(ll x=k;x>=0;x--){
			//cout<<x<<": "<<n<<"\n";
			/*if(n&(1ll<<x)){
				//cout<<"-"<<m<<" ("<<x<<")\n";
				n-=m;
			}*/
			n%=m;
			res+=n;
			n*=2;
		}
		//cout<<n<<"\n";
		if(!n)cout<<res<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}

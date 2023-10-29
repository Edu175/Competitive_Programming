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

ll fn(ll n){return n*(n+1)/2;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,x,y; cin>>n>>x>>y;
		ll m=lcm(x,y);
		ll cm=n/m;
		ll cx=n/x-cm,cy=n/y-cm;
		ll res=fn(n)-fn(n-cx)-fn(cy);
		/*cout<<n<<" "<<x<<" "<<y<<": "<<m<<"\n";
		cout<<cx<<" "<<cy<<" "<<cm<<"\n";
		cout<<fn(n)<<"-"<<fn(n-cx)<<"-"<<fn(cy)<<"\n";*/
		cout<<res<<"\n";
		//cout<<"\n";
	}
	return 0;
}

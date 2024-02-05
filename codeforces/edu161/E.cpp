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
const ll INF=5e8;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll x; cin>>x;
		vector<ll>a;
		fore(i,0,63){
			if(x<=1)break;
			if(x%2)a.pb(INF);
			a.pb(i);
			x/=2;
		}
		cout<<SZ(a)<<"\n";
		imp(a);
	}
	return 0;
}

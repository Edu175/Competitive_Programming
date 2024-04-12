#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

set<ll>st={1,2,4,7,10,20,23,26,50,53,270,273,276,282,285,288,316,334,337,340,346,359,362,365,386,389,392,566,630,633,636,639,673,676,682,685,923,926,929,932,1222};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(!st.count(n))cout<<"first\n";
		else cout<<"second\n";
	}
	return 0;
}

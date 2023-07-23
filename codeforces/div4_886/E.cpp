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
const ll MAXN=2e5+5;
ll a[MAXN];
ll n;
__int128 C;
bool can(ll w){
	__int128 sum=0;
	fore(i,0,n){
		__int128 x=a[i]+2*w;
		//if(x>sq)return 0;
		if(x*x>C)return 0;
		sum+=x*x;
		if(sum>C)return 0;
	}
	return sum<=C;
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll c;cin>>n>>c;C=c;
		fore(i,0,n)cin>>a[i];
		ll l=0,r=1e18;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))l=m+1;
			else r=m-1;
		}
		cout<<r<<"\n";
	}
	return 0;
}

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
typedef unsigned long long ull;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll>a(n),b(m);
		fore(i,0,n)cin>>a[i];
		fore(i,0,m)cin>>b[i];
		ll rmn=1e10,rmx=0;
		fore(mk,0,1ll<<m){
			ll x=0,s=0;
			fore(i,0,m)if(mk&(1ll<<i))s|=b[i];
			fore(i,0,n)x^=a[i]|s;
			rmn=min(rmn,x);
			rmx=max(rmx,x);
		}
		cout<<rmn<<" "<<rmx<<"\n";
	}
	return 0;
}

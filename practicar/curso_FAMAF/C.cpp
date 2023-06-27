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
	ll n,q; cin>>n>>q;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll sp[n+1]={};
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	while(q--){
		ll x,y; cin>>x>>y;
		cout<<sp[n-x+y]-sp[n-x]<<"\n";
	}
	return 0;
}

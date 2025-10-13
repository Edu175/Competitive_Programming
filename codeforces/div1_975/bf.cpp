#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n;
vv a;

ll f(ll i, ll mn, ll mx, ll b, ll cant){
	if(i==n){return cant?mn+mx+cant:0;}
	ll go0=f(i+1,mn,mx,0,cant);
	if(b)return go0;
	ll go1=f(i+1,min(mn,a[i]),max(mx,a[i]),1,cant+1);
	return max(go0,go1);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		a=vv(n);
		fore(i,0,n)cin>>a[i];
		cout<<f(0,1e18,-1,0,0)<<"\n";
	}
	return 0;
}

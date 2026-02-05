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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n; n<<=1;
		vv a(n);
		map<ll,ll> mp;
		fore(i,0,n)cin>>a[i],mp[a[i]]++;
		vv sol;
		ll xr=0;
		for(auto [x,c]:mp){
			if(c&1)sol.pb(x),c--;
			fore(i,0,c/2)xr^=x;
		}
		ll win=SZ(sol)<=2;
		if(win){
			if(!SZ(sol))win&=xr==0;
			else {
				assert(SZ(sol)==2);
				win=0;
				fore(i,0,2)win|=(xr^sol[i])==0;
			}
		}
		if(win)cout<<"Menji\n";
		else cout<<"Bot\n";
	}
	return 0;
}

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
	ll n; cin>>n;
	vv a(n),b(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	ll A=0,B=0;
	ll fg=1;
	vv ty(n); // -1 0 1
	fore(i,0,n){
		ll da=a[i]-A; A=a[i];
		ll db=b[i]-B; B=b[i];
		if(da<0||db<0||da>1||db>1)fg=0;
		if(da+db>1)fg=0;
		ty[i]=da-db;
	}
	
	return 0;
}

#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x)  for(auto a:x){cout<<a<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll>  ii;

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv d(n-1);
	ll g=0,sum=0;
	fore(i,0,n-1){
		d[i]=abs(a[i]-a[i+1]);
		sum+=d[i];
		g=gcd(g,d[i]);
	}
	ll x=a[0],m=2*g;
	if(m){
		x%=m; if(!x)x+=m;
	}
	ll res=x+sum;
	cout<<res<<"\n";
	return 0;
}
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
int fpow(ll a, ll b,ll MOD){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=r*a%MOD; b>>=1; a=a*a%MOD;}
	return r;
}
int main(){FIN;
	ll n,p,k; cin>>n>>p>>k;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]=a[i]*a[i]%p*a[i]%p;
	
	vv b;
	ll z=0;
	fore(i,0,n){
		if(!a[i])z++;
		else b.pb(a[i]);
	}
	ll res=z*(z-1)/2+SZ(b)*z;
	if(k)res=0;
	n=SZ(b);
	map<ll,ll>mp;
	fore(i,0,SZ(b)){
		ll o=fpow(b[i],p-2,p);
		o=o*k%p;
		// cout<<i<<": "<<b[i]<<" "<<o<<"\n";
		res+=mp[o];
		mp[b[i]]++;
	}
	cout<<res<<"\n";
	return 0;
}

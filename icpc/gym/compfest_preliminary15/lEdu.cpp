#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll piso(ll a, ll b){
	ll sig=(a<0)^(b<0);
	a=abs(a),b=abs(b);
	if(sig)return -(a+b-1)/b;
	return a/b;
}
ll suma(ll a, ll d, ll n){
	assert(n>=0);
	a++;
	return a*n+n*(n-1)/2*d;
}
int main(){
	JET
	ll n,m; cin>>n>>m;
	ll res=0,ans=1;
	fore(k,2,m+1){
		// cout<<k<<":"<<endl;
		ll g=gcd(k,n);
		ll j=0,resi=0;
		while(j<n/g){
			ll x=(k-1+j*k)%n;
			ll d=(n-x+k-1)/k;
			ll i=piso(j-x,k-1)+1;
			ll s=suma(x+i*k,k,d-i);
			// cout<<j<<" "<<x<<": "<<d<<" "<<i<<" += "<<s<<endl;
			// cout<<j-x<<"/"<<(k-1)<<"+1 = "<<i<<endl;
			assert(x+i*k>j+i);
			assert(!(x+(i-1)*k>j+i-1));
			assert(i>=0);
			resi+=s;
			j+=d;
		}
		// cout<<resi<<endl<<endl;
		if(resi>res)res=resi,ans=k;
	}
	cout<<ans<<"\n";
	return 0;
}
#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ld tau=2*acosl(-1);

int main(){
    JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	map<ll,ll>mp;
	sort(ALL(a)); reverse(ALL(a));
	mp[0]=a[0];
	ll l=-1,r=1;
	fore(i,1,n){
		if(i&1)mp[r++]=a[i];
		else mp[l--]=a[i];
	}
	vv b;
	for(auto i:mp)b.pb(i.snd);
	ll res=0;
	fore(i,0,n)res+=b[i]*b[(i+1)%n];
	ld alp=tau/n;
	ld ans=res*sinl(alp)/2.;
	cout<<fixed<<setprecision(3)<<ans<<"\n";
    return 0;
}
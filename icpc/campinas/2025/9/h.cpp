#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n,k; cin>>n>>k;
	vv a(n+2);
	vv obj(k);
	fore(i,0,n) cin>>a[i];
	fore(i,0,k) cin>>obj[i];
	fore(i,0,n){
		ll cnt=0;
		fore(j,0,k){
			if(obj[j]&(1ll<<i)){
				cnt++;
				// cout<<j<<" "<<cnt<<"\n";
			}
		}
		if(cnt>a[i]){
			// cout<<a[i]<<" "<<cnt<<" ";
			cout<<"NO\n";
			return 0;
		}
		ll s = a[i]-cnt;
		a[i+1]+=(s/2);
	}
	cout<<"YES\n";
	return 0;
}
#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(v,a) memset((a),(v),sizeof(a))
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<ii> vi;
bool is(vv &r){
	ll n=SZ(r);
	fore(i,0,n/2){
		if(r[i]!=r[n-i-1]) return false;
	}
	return true;
}
int main(){
		ET;
	ll n; cin>>n;
	if(n==2) {cout<<"*\n"; return 0;}
	vv res={n-1};
	ll q=sqrt(n)+1;
	fore(i,2,q){
		if(n%i==0&&(n/i-1)>i) res.pb((n/i)-1);
		ll m=n;
		vv r;
		while(m){
			r.pb(m%i);
			m/=i;
		}
		if(is(r))res.pb(i);
	}
	sort(ALL(res));
	fore(i,0,SZ(res)) cout<<res[i]<<" ";; cout<<"\n";
}
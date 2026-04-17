#include<bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	ll tot = 100;
	ll r = 100;
	fore(i,0,n){
		ll x; cin>>x;
		tot+=x;
		r = max(r,tot);
	}
	cout<<r<<"\n";
	return 0;
}
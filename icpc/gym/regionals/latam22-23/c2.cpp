#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

string ans;
void f(ll p, ll h, ll k, ll n){
	if(n==1)return;
	ll subo=h>>k&1;
	cout<<p<<" "<<h<<" "<<k<<" "<<n<<": "<<subo<<"\n";
	if(!subo^(p<n/2))ans.pb('L');
	else ans.pb('R');
	f((subo?n-1-p:p),h,k+1,n/2);
}

int main(){
	ET
	ll n,p,h; cin>>n>>p>>h; p--,h--;
	f(p,h,0,1ll<<n);
	cout<<ans<<"\n";
}
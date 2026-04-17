#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll m[481];
int main(){
	ET
	ll n,x; cin>>n>>x;
	vector<ii> a(n);
	fore(i,0,n) cin>>a[i].fst>>a[i].snd;
	fore(i,0,481){
		fore(j,0,n){
			ll mod1=a[j].fst-1, mod2=(a[j].fst+a[j].snd);
			m[i]+=max(mod2-i,0ll)/x-max(mod1-i,0ll)/x+(mod1<i&&i<=mod2);
			//if(i==451) cout<<(mod2-i)/x<<" "<<(mod1-i)/x<<"\n";
		}
	}
	ll mi=1e10;
	ll pos=0;
	fore(i,0,481){
		if(mi>m[i]){
			mi=m[i];
			pos=i;
		}
	}
	cout<<pos<<" "<<mi<<"\n";
}
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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n,m;

vector<pair<ld,vv>> all;
vv a;
void f(ld sum){
	if(SZ(a)==n){
		sum+=1./lcm(a.back(),a[0]);
		all.pb({sum,a});
		return;
	}
	fore(c,(SZ(a)?a.back():0)+1,m+1){
		ld term=SZ(a)?1./lcm(a.back(),c):0;
		a.pb(c);
		f(sum+term);
		a.pop_back();
	}
}

int main(){FIN;
	// ll t; cin>>t;
	// while(t--){
		ll k; cin>>n>>m>>k;
		f(0);
		sort(ALL(all));
		reverse(ALL(all));
		fore(i,0,min(SZ(all),int(k))){
			auto [fst,snd]=all[i];
			cout<<fst<<": ";
			imp(snd);
		}
	// }
	return 0;
}

#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;
int main(){
	JET
	ll _; cin>>_; while(_--){
		ll n; cin>>n;
		vv k(n),a(n,0);
		vector<ld> r; 
		fore(i,0,n){
			cin>>k[i];
			fore(j,0,k[i]){
				ll x; cin>>x;
				a[i]+=x*(x-1);
			}
			r.pb(ld(a[i])/ld(k[i]));
		}
		cout<<r[0]<<" "<<r[1]<<"\n";
	}
	
	return 0;
}
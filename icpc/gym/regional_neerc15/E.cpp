#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	#ifdef ONLINE_JUDGE
	freopen("easy.in","r",stdin);     freopen("easy.out","w",stdout);
	#endif
	ll n,k; cin>>n>>k;
	vv p[n]; 
	ll mx=0;
	fore(i,0,n) {
		ll sz; cin>>sz;
		mx=max(sz,mx);
		fore(j,0,sz){
			ll x; cin>>x;
			p[i].pb(x);
		}	
	}
	ll h=0;
	fore(i,0,mx)if(k){
		fore(j,0,n)if(k){
			if(i<SZ(p[j])){
				if((i<SZ(p[j])?p[j][i]:-1ll)>=h){
					h+=p[j][i];
					k--;
				}
			}
			else if(h<=50){
				h+=50;
				k--;
			}
		}
	}
	h+=k*50;
	cout<<h<<"\n";
	
	return 0;
}
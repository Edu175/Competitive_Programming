#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef long long LL;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef vector<ii> vi;
bool check(ll x){
	ll u=0;
	while(x){
		if(u&&(x&1)) return false;
		u=(x&1);
		x>>=1;
	}
	return true;
}
int main(){
	JET
	// vv T={11,6,15};
	vv P;
	set<ll> C[16];

	fore(i,0,16){
		if(check(i)) {
			P.pb(i);
		}
	}
	// show(P);
	fore(i,0,16){
		fore(j,0,16){
			fore(t,0,16) C[t].clear();
			for(auto p: P){
				C[p^i].insert(i);
				C[p^j].insert(j);
			}
			bool bad=0;
			fore(t,0,16) if(SZ(C[t])<=1){
				bad=1;
			}
			if(!bad)cout<<i<<" "<<j<<"\n";
		}
	}
	return 0;
}
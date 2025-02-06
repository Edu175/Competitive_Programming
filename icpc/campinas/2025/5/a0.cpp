#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a;i<b;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef long long LL;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
// random_device rd;
// mt19937 rng;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll ITER=25,MAXN=5e5+1;
vv pos[MAXN];
// ll cnt[MAXN];
ll a[MAXN];
const LL mul=3543521,add=6543213,MOD=1777771;
LL ra=5;
int main(){
	JET
	ll n,q; cin>>n>>q;
	// mset(cnt,0);
	fore(i,0,n){
		cin>>a[i];
		a[i]--;
		// cnt[a[i]]++;
	}
	// fore(i,0,n)pos[i].reserve(cnt[i]);
	fore(i,0,n)pos[a[i]].pb(i);
	// cerr<<q<<" queries\n";
	// ll dbg=0;
	while(q--){
		ll l,r; cin>>l>>r; l--;
		ll res=-1;
		
		vv toco;
		
		fore(_,0,ITER){
			ra=(ra*mul+add)%MOD;
			ll k=a[(ra)%(r-l)+l];
			ll q=lower_bound(ALL(pos[k]),r)-lower_bound(ALL(pos[k]),l);
			if(q*2>r-l){
				res=k;
				break;
			}
		}
		cout<<res+1<<"\n"; //dbg++;
	}
	// cerr<<dbg<<" answered\n";
	return 0;
}
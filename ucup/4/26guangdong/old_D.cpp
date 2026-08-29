#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv; 
// const ll MAXN=2e5+5,INF=1e10;

// ll dp[MAXN*2][2][2];
struct rang{ll l,r,c;};
bool operator<(rang a, rang b){return a.l<b.l;}
bool inr(rang a, ll x){
	if(a.l>a.r)return a.l<=x||x<=a.r;
	return a.l<=x&&x<=a.r;
}
int main(){
    JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n-3);
		fore(i,0,n-3)cin>>a[i],a[i]--;
		set<ll> st; fore(i,0,3*n)st.insert(i);
		vector<ii> adj;
		for(auto x:a){
			auto it=st.lower_bound(x+n);
			ll l=*prev(it)%n;
			ll r=*next(it)%n;
			fore(h,0,3)st.erase(x+n*h);
			adj.pb({l,r});
		}
		ll mis=0;
		vv bl(n);
		set<rang> rans; // [], can be circular
		ll cad=0;
		ll cir=0;
		auto add=[&](rang a){
			rans.insert(a);
			cad+=(a.c+1)/2;
		};
		auto rem=[&](rang a){
			cad-=(a.c+1)/2;
			ll did=rans.erase(a);
			assert(did);
		};
		vv L(n),R(n); fore(i,0,n)L[i]=(i-1+n)%n,R[i]=(i+1)%n;
		auto sac=[&](ll x){
			if(cir){
				assert(!SZ(rans));
				add({x+1,x-1});
				cir=0;
				return;
			}
			auto it=rans.lower_bound({x,-1});
			if(it==rans.begin())it=rans.end();
			if(it==rans.begin()||!inr(*prev(it),x))return;
			auto e=*prev(it);
			rem(e);
			if(e.l!=x){
				ll r=L[x];
				add({})
			}
		};
		auto out=[&](ll x){
			L[R[x]]=L[x];
			R[L[x]]=R[x];
			sac(x);
		};
		fore(i,0,SZ(a)){
			ll x=a[i];
			auto [l,r]=adj[i];
			if(!bl[x]){
				mis++;
				bl[l]=bl[r]=1;
				// saco los 3
				
			}
		}
	}
    return 0;
}
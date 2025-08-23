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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		auto can=[&](ll m)->pair<bool,ii>{ // E med >= m ?
			vv b(n);
			fore(i,0,n)b[i]=a[i]>=m?1:-1;
			vv sp(n+1);
			fore(i,0,n)sp[i+1]=sp[i]+b[i];
			ii mn={*max_element(ALL(sp))+5,-1};
			fore(r,1,n+1){
				if(r-k>=0)mn=min(mn,(ii){sp[r-k],r-k});
				if(sp[r]-mn.fst>=0)return {1,{mn.snd,r}};
			}
			return {0,{-1,-1}};
		};
		ll l=0,r=n+1;
		while(r-l>1){
			ll m=(l+r)/2;
			auto rq=can(m);
			if(rq.fst)l=m;
			else r=m;
		}
		ll m=l;
		auto rq=can(m);
		assert(rq.fst);
		auto [s,e]=rq.snd;
		cout<<m<<" "<<s+1<<" "<<e<<"\n";
	}
	return 0;
}

#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#define maxig(a,b) a=max(a,b)
ll proj(ll x, ll y, ll bo){return bo?x-y:x+y;}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll H; cin>>H;
		ll T=2*H;
		auto mod=[&](ll p){return (p%T+T)%(T);};
		auto Proj=[&](ll x, ll y, ll bo){
			return mod(proj(x,y,bo));
		};
		vector<array<ll,3>> all;
		all.pb({0,0,0});
		fore(ty,0,2){
			ll n; cin>>n;
			fore(i,0,n){
				ll x,y; cin>>x>>y;
				all.pb({x,y,ty});
			}
		}
		sort(ALL(all));
		reverse(ALL(all));
		vector<unordered_map<ll,ll>> bu(2);
		ll ans=0;
		for(auto [x,y,ty]:all){
			vv res(2);
			// cerr<<x<<","<<y<<":\n";
			fore(bo,0,2){
				ll same=bu[bo][Proj(x,y,bo)];
				ll d=bo?H-y:y;
				ll xp=x+d;
				ll yp=y+(bo?d:-d);
				ll otr=bu[bo^1][Proj(xp,yp,bo^1)];
				res[bo]=max(same,otr)+ty;
				// cerr<<bo<<": "<<xp<<" "<<yp<<": "<<res[bo]<<"\n";
			}
			if(!ty)res=vv(2,*max_element(ALL(res)));
			fore(bo,0,2){
				ll cur=res[bo];
				maxig(bu[bo][Proj(x,y,bo)],cur);
			}
			if(!x&&!y)ans=res[1];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
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
const ll MAXN=2e5+5,INF=1e10;

ll dp[MAXN*2][2][2];

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
		vector<ii> sted=adj;
		fore(i,0,n)sted.pb({i,(i+1)%n});
		sort(ALL(sted));
		sted.resize(unique(ALL(sted))-sted.begin());
		auto get_idx=[&](ii a)->ll {
			auto ptr=lower_bound(ALL(sted),a);
			assert(ptr!=sted.end()&&*ptr==a);
			return ptr-sted.begin();
		};
		ll m=SZ(sted);
		assert(m<=MAXN*2);
		fore(i,0,m)fore(j,0,2)fore(k,0,2)dp[i][j][k]=0; // initial adj start with 0
		#define f(u,v,bu,bv) dp[get_idx({(u),(v)})][bu][bv]
		fore(i,0,SZ(a)){
			ll x=a[i]; auto [l,r]=adj[i];
			ll idx=get_idx({l,r});
			fore(bl,0,2)fore(br,0,2){
				auto &cur=dp[idx][bl][br];
				cur=INF;
				if(!bl&&!br)continue; // edge l,r
				fore(bx,0,2){
					ll cand=f(l,x,bl,bx)+f(x,r,bx,br)+bx;
					cur=min(cur,cand);
				}
			}
		}
		vv us; // ultimos
		for(auto i:st)if(i<n)us.pb(i);
		ll z=SZ(us);
		assert(z==3);
		ll res=INF;
		fore(mk,0,1ll<<z){
			ll cur=0;
			fore(i,0,z){
				ll j=(i+1)%z;
				cur+=(mk>>i&1);
				cur+=f(us[i],us[j],(mk>>i&1),(mk>>j&1));
			}
			res=min(res,cur);
		}
		cout<<res<<"\n";
	}
    return 0;
}
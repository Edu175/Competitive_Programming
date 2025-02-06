#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll K=63,INF=ll(1e18)+5;

ll tec(ll a, ll b){return (a+b-1)/b;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i];
		vector<ii> all;
		fore(i,0,n)cin>>b[i],all.pb({b[i],i});
		sort(ALL(all));
		set<ll>st={-1,n};
		vector<ii> ra(n);
		vv tim(n);
		ll rt=-1;
		vector<vv>g(n);
		fore(_,0,n){
			auto [v,i]=all[_];
			auto it=st.lower_bound(i);
			ll l=*prev(it),r=*it;
			ll p=l;
			if(r!=n&&(l==-1||tim[r]>tim[l]))p=r;
			tim[i]=_;
			if(p!=-1)g[p].pb(i);
			else rt=i;
			// cout<<i<<" "<<v<<": "<<p<<"\n";
			st.insert(i);
		}
		// cout<<rt<<" rt\n";
		vector<vv>dp(n+3,vv(K+5,INF));
		reverse(ALL(all));
		for(auto [v,i]:all){
			fore(k,0,K){
				auto &res=dp[i][k];
				ll go0=-1; // no uso
				// cout<<i<<": ";
				// imp(g[i]);
				if(SZ(g[i])==1)go0=dp[g[i][0]][k];
				else if(SZ(g[i])==2){
					go0=INF;
					ll l=g[i][0],r=g[i][1];
					fore(c,0,k+1)
						go0=min(go0,max(dp[l][c],dp[r][k-c]));
				}
				go0=max(go0,a[i]);
				
				ll go1=k?tec(dp[i][k-1],v):INF; // uso
				
				res=min(go0,go1);
				// if(k<=3){
				// 	cout<<i<<" "<<v<<" "<<k<<": "<<res<<"\n";
				// }
			}
			
		}
		ll res=-1;
		fore(k,0,K)if(dp[rt][k]==1){res=k;break;}
		cout<<res<<"\n";
	}
	return 0;
}

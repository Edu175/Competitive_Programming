#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<vv> g(n,vv(n));
		vector<ii>ed;
		fore(i,0,m){
			ll u,v; string s; cin>>u>>s>>v; u--,v--;
			if(s=="->")g[u][v]++;
			else ed.pb({u,v});//,cout<<u<<" "<<v<<"\n";
		}
		ll ans=0;
		fore(mk,0,1ll<<SZ(ed)){
			fore(i,0,SZ(ed)){
				// cout<<ed[i].fst<<" "<<ed[i].snd<<" edge\n"<<endl;
				if(mk>>i&1)g[ed[i].fst][ed[i].snd]++;
				else g[ed[i].snd][ed[i].fst]++;
			}
			vv dp(n,-1);
			vv vis(n);
			auto f=[&](ll x, auto &&f){
				auto &res=dp[x];
				if(res!=-1)return res;
				vis[x]=1;
				res=0;
				fore(y,0,n)if(g[x][y]){
					if(vis[y]==1){
						cout<<"hay ciclo\n";
						exit(0);
					}
					res=max(res,f(y,f)+1);
				}
				vis[x]=2;
				return res;
			};
			ll res=0;
			fore(i,0,n)res=max(res,f(i,f));
			ans=max(ans,res);
			fore(i,0,SZ(ed)){
				if(mk>>i&1)g[ed[i].fst][ed[i].snd]--;
				else g[ed[i].snd][ed[i].fst]--;
			}

		}
		cout<<ans<<"\n";
	}
	return 0;
}
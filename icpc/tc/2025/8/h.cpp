#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<vv> g(n);
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			// cout<<u<<" "<<v<<endl;
			g[u].pb(v);
			g[v].pb(u);
		}
		vv deg(n),vis(n);
		queue<ll>q;
		fore(x,0,n){
			if((deg[x]=SZ(g[x]))==1){
				q.push(x);
			}
		}
		vector<vector<ii>>v(n);
		vector<ii>ans;
		ll fg=1;
		while(SZ(q)){
			auto x=q.front(); q.pop();
			auto &vec=v[x];
			sort(ALL(vec));
			for(ll i=0;i+2<SZ(vec);i+=2){
				ans.pb({vec[i].snd,vec[i+1].snd});
			}
			ll isr=!deg[x];
			if(SZ(vec)){
				if(SZ(vec)&1)vec={vec.back()};
				else {
					auto au=vec[SZ(vec)-2],u=vec[SZ(vec)-1];
					ii ar;
					if((au.fst==1&&u.fst==1)||isr){
						ar={au.snd,u.snd},vec.clear();
					}
					else {
						assert(u.fst>1);
						ar={x,u.snd};
						vec={au};
					}
					ans.pb(ar);
				}
			}
			
			if(isr){
				// cerr<<"root "<<x<<"\n";
				if(SZ(vec)){
					ii u=vec[0];
					fg&=u.fst>1;
					ans.pb({x,u.snd});
				}
				break; // break
			}
			if(!SZ(vec))vec.pb({0,x});
			ii u=vec[0]; u.fst++;
			vis[x]=1;
			for(auto y:g[x])if(!vis[y]){
				if((--deg[y])<=1)q.push(y);
				v[y].pb(u);
			}
		}
		if(!fg)cout<<"-1\n";
		else {
			// cout<<"YES\n";
			cout<<SZ(ans)<<"\n";
			for(auto [x,y]:ans)cout<<x+1<<" "<<y+1<<"\n";
		}
	}
	return 0;
}
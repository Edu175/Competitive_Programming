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
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5;

vv g[MAXN];
ll d[MAXN],fa[MAXN];

void dfs(ll x){
	for(auto y:g[x])if(y!=fa[x]){
		fa[y]=x;
		d[y]=d[x]+1;
		dfs(y);
	}
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		d[0]=0; fa[0]=-1;
		dfs(0);
		vector<vv> h(n);
		fore(i,0,n)h[d[i]].pb(i);
		ll mx=0;
		fore(i,0,n)mx=max(mx,(ll)SZ(h[i]));
		ll bad=0;
		fore(i,0,n){
			ll cant=SZ(h[i]);
			set<ll> st;
			for(auto x:h[i])st.insert(fa[x]);
			if(cant==mx&&SZ(st)==1)bad=1;
		}
		ll z=mx+bad;
		
		vv pos(n,-1);
		pos[0]=0;
		fore(d,1,n){
			auto a=h[d];
			if(!SZ(a))break;
			vector<ii> b;
			set<ll> st;
			for(auto x:a)b.pb({fa[x],x}),st.insert(pos[fa[x]]);
			sort(ALL(b));
			ll po=0;
			auto av=[&](){
				while(po<z&&st.count(po))po++;
				assert(po<z);
			};
			// cerr<<d<<" d:\n";
			// imp(v)
			// impr(b)
			// cout<<endl;
			ll prev=-1;
			vv uf,ux;
			for(auto [f,x]:b){
				if(f!=prev)uf.pb(f),ux.pb(x);
				else {
					av();
					pos[x]=po++;
				}
				prev=f;
			}
			// cerr<<"uf: "; imp(uf)
			// cerr<<"ux: "; imp(ux)
			// cout<<endl;
			if(SZ(ux)==1){
				av();
				ll x=ux[0];
				pos[x]=po++;
			}
			else {
				assert(SZ(ux)>=2);
				rotate(ux.begin(),ux.begin()+1,ux.end());
				fore(i,0,SZ(ux))pos[ux[i]]=pos[uf[i]];
			}
		}
		vector<vv> ans(z);
		fore(x,0,n){
			assert(pos[x]!=-1);
			ans[pos[x]].pb(x);
		}
		cout<<SZ(ans)<<"\n";
		for(auto v:ans){
			cout<<SZ(v)<<" ";
			for(auto i:v)cout<<i+1<<" ";
			cout<<"\n";
		}
		// cout<<endl;
	}
	return 0;
}

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

vector<vector<string>> info;

bool f(ll x, ll m, ll y){ // true iff d(x,m)=d(m,y)
	if(x>y)swap(x,y);
	ll i=x,j=y-(i+1);
	return info[i][j][m]-'0';
}

void operator+=(vv &a, vv b){
	for(auto i:b)a.pb(i);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		info.resize(n-1);
		fore(i,0,n-1){
			auto &v=info[i];
			v.resize(n-(i+1));
			fore(j,0,n-(i+1))cin>>v[j];
		}
		ll rt=0;
		vector<vv> ds;
		fore(x,0,n)if(x!=rt){
			ll did=0;
			fore(j,0,SZ(ds)){
				ll y=ds[j].back();
				if(f(x,rt,y)){
					ds[j].pb(x);
					did=1;
					break;
				}
			}
			if(!did)ds.pb({x});
		}
		auto doit=[&](vv bag)->vector<ii> {
			vv vis(n); vis[rt]=1;
			vector<ii> ed;
			vv fa(n,-1),D(n);
			for(auto i:bag)ed.pb({rt,i}),vis[i]=1,fa[i]=rt;
			auto dfs=[&](ll x, auto &&dfs)->void {
				vis[x]=1;
				D[x]=D[fa[x]]+1;
				fore(y,0,n)if(!vis[y]&&f(fa[x],x,y)){
					fa[y]=x;
					ed.pb({x,y});
					dfs(y,dfs);
				}
			};
			D[rt]=0;
			for(auto i:bag)dfs(i,dfs);
			// cerr<<"doit "; imp(bag)
			// imp(vis)
			// imp(D)
			// imp(fa)
			// for(auto i:ed)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
			if(count(ALL(vis),0))return {};
			vector<vv> mem(n,vv(n,-1));
			auto lca=[&](ll x, ll y, auto &&lca)->ll {
				auto &res=mem[x][y];
				if(res!=-1)return res;
				if(x==y)return res=x;
				if(D[x]>D[y])swap(x,y);
				return res=lca(x,fa[y],lca);
			};
			auto dis=[&](ll x, ll y){
				ll ret=D[x]+D[y]-2*D[lca(x,y,lca)];
				// cerr<<"dis "<<x<<","<<y<<": "<<ret<<"\n";
				return ret;
			};
			fore(x,0,n)fore(y,x+1,n)fore(z,0,n){
				if(ll(dis(x,z)==dis(y,z))!=ll(f(x,z,y))){
					// cerr<<f(x,z,y)<<" f\n";
					// cerr<<"failed "<<x<<","<<y<<" "<<z<<"\n";
					return {};
				}
			}
			return ed;
		};
		vector<ii> ed;
		fore(i,0,SZ(ds)){
			auto cur=doit(ds[i]);
			if(SZ(cur)){ed=cur;break;}
		}
		if(SZ(ed)){
			cout<<"Yes\n";
			for(auto [x,y]:ed)cout<<x+1<<" "<<y+1<<"\n";
		}
		else cout<<"No\n";
	}
	return 0;
}

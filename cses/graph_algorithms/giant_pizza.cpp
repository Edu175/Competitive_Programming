#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ii>a[MAXN];
vector<ll>b[MAXN][2];
ll vis[MAXN];
vector<ll>pth;

bool dfs(ll x, ll c){
	vis[x]=c;
	pth.pb(x);
	ll ret=1;
	for(auto i:b[x][c^1]){
		ii d=a[i][0]; if(d.fst==x)d=a[i][1];
		if(vis[d.fst]!=-1){
			if(vis[d.fst]!=d.snd){
				ret=0;
				break;
			}
			continue;
		}
		if(!dfs(d.fst,d.snd)){
			ret=0;
			break;
		}
	}
	//if(!ret)vis[x]=-1;
	//cout<<x<<" "<<c<<": "<<ret<<"\n";
	return ret;
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,n){
		fore(j,0,2){
			char c; cin>>c;
			ll v; cin>>v; v--;
			//cout<<"a: "<<i<<" --> "<<v<<" "<<(c=='+')<<"\n";
			//cout<<"b: "<<v<<" "<<(c=='+')<<" --> "<<i<<"\n";
			a[i].pb({v,(c=='+')});
			b[v][(c=='+')].pb(i);
		}
	}
	mset(vis,-1);
	ll flag=1;
	fore(i,0,m){
		if(!flag)break;
		//cout<<i<<":\n";
		if(vis[i]==-1){
			//cout<<"\t0:\n";
			if(!dfs(i,0)){
				for(auto j:pth)vis[j]=-1;
				//fore(h,0,m)cout<<vis[h]<<" "; cout<<"\n";
				//cout<<"\t1:\n";
				if(!dfs(i,1))flag=0;
				//fore(h,0,m)cout<<vis[h]<<" "; cout<<"\n";
			}
		}
	}
	if(!flag)cout<<"IMPOSSIBLE\n";
	else {
		fore(i,0,m){
			if(vis[i])cout<<"+ ";
			else cout<<"- ";
		}
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home


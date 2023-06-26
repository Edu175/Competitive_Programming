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
const ll MAXN=105,INF=1e12;

ll g[MAXN][MAXN];
//ll f[MAXN][MAXN];
ll is[MAXN];
//vector<ii>ed;
vector<ll>cmp;
vector<pair<vector<ll>,ll>>res;
ll inf=0;
void prim(ll n){
	is[n-1]=1; cmp.pb(n-1);
	while(is[0]==0){
		//imp(cmp);
		ll mn=INF;
		for(auto i:cmp)fore(j,0,n)if(!is[j])mn=min(mn,g[i][j]);
		if(mn==INF){
			inf=1;
			break;
		}
		//cout<<mn<<"\n";
		res.pb({cmp,mn});
		vector<ll>add;
		for(auto i:cmp)fore(j,0,n)if(!is[j]&&g[i][j]!=INF){
			g[i][j]-=mn;
			g[j][i]-=mn;
			if(g[i][j]<=0)add.pb(j),is[j]=1;
		}
		for(auto i:add)cmp.pb(i);
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,n+3)fore(j,0,n+3)g[i][j]=INF;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u][v]=w;
		g[v][u]=w;
	}
	prim(n);
	if(inf){
		cout<<"inf\n";
		return 0;
	}
	vector<pair<vector<ll>,ll>>ans;
	ll sum=0;
	for(auto i:res){
		vector<ll>isi(n,1);
		for(auto j:i.fst)isi[j]=0;
		ans.pb({isi,i.snd});
		sum+=i.snd;
	}
	cout<<sum<<" "<<SZ(ans)<<"\n";
	for(auto i:ans){
		for(auto j:i.fst)cout<<j;
		cout<<" "<<i.snd<<"\n";
	}
	return 0;
}

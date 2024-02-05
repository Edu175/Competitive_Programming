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
const ll MAXN=2005,MAXM=5005;

vector<ii> g[MAXN];
ll lw[MAXN],dis[MAXN],is[MAXN],tk[MAXN],vis[MAXM];
ll cnt=0;
void dfs(ll x){
	lw[x]=dis[x];
	for(auto [y,ed]:g[x])if(!tk[y]&&!vis[ed]){
		cnt+=(x==0);
		vis[ed]=1;
		if(lw[y]==-1){
			dis[y]=dis[x]+1;
			dfs(y);
			lw[x]=min(lw[x],lw[y]);
			is[x]|=(lw[y]>=dis[x]);
		}
		else lw[x]=min(lw[x],dis[y]);
	}
}
void art_points(ll rt=0){
	mset(lw,-1); mset(is,0); mset(vis,0);
	dis[rt]=0; cnt=0;
	dfs(rt);
	//cout<<"art "<<rt<<": "<<cnt<<"\n";
	is[rt]=(cnt>1);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n1,n2,n,m; cin>>n1>>n2>>m; n=n1+n2;
		fore(i,0,n){
			g[i].clear();
			tk[i]=0;
		}
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
		}
		vector<ll>a;
		set<ll>st={0};
		while(SZ(a)<n1){
			art_points(*st.begin());
			/*imp(a);
			imp(st);
			fore(i,0,n)cout<<is[i]<<" ";;cout<<endl;*/
			ll x=-1;
			for(auto i:st)if(!is[i]){x=i;break;}
			if(x==-1)while(1);
			//assert(x!=-1);
			st.erase(x);
			for(auto [i,sdf]:g[x])if(!tk[i])st.insert(i);
			tk[x]=1; a.pb(x);
		}
		vector<ll>b;
		fore(i,0,n)if(!tk[i])b.pb(i);
		for(auto i:a)cout<<i+1<<" ";
		cout<<"\n";
		for(auto i:b)cout<<i+1<<" ";
		cout<<"\n";//==========\n";
	}
	return 0;
}

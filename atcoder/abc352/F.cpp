#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll N=16;
vector<ii> g[N];
ll vis[N];
vector<ii>c;

void dfs(ll x, ll d){
	vis[x]=1;
	c.pb({d,x});
	for(auto [y,w]:g[x])if(!vis[y])dfs(y,d+w);
}
ll dp[N+5][1<<N];
vector<ll>ms;
set<ll>ofs[N];
ll u,k,n;
string cv(ll x){
	string s;
	fore(i,0,n)s.pb('0'+(x>>i&1));
	return s;
}
ll f(ll i, ll mk){
	ll &res=dp[i][mk];
	if(res!=-1)return res;
	if(i==k)return mk==u;
	res=0;
	fore(j,0,n){
		if((ms[i]<<j)<=u&&f(i+1,mk|(ms[i]<<j)))res=1,ofs[i].insert(j);
		//,cout<<i<<" -> "<<j<<"\n";
	}
	//if(res)cout<<i<<" "<<cv(mk)<<"\n";
	return res;
}
int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll a,b,c; cin>>a>>b>>c; a--,b--;
		g[b].pb({a,c});
		g[a].pb({b,-c});
	}
	ll cnt=0;
	
	vector<ll>pa(n),my(n);
	fore(x,0,n)if(!vis[x]){
		c.clear();
		dfs(x,0);
		sort(ALL(c));
		ll of=-c[0].fst;
		ll mk=0;
		for(auto [d,x]:c){
			d+=of;
			mk|=1<<d;
			pa[x]=cnt;
			my[x]=d;
			//cout<<x<<","<<d<<" ";
		}
		//cout<<"\n";
		//cout<<mk<<"\n";
		cnt++;
		ms.pb(mk);
	}
	k=cnt;
	u=(1<<n)-1;
	/*for(ll i=k-1;i>=0;i--)fore(mk,0,1<<n){
		auto &res=dp[i][mk];
		fore(j,0,n){
			if((ms[i]<<j)<=u&&dp[i+1][mk|(ms[i]<<j)])res=1,ofs[i].insert(j);
		}
		
	}*/
	mset(dp,-1);
	f(0,0);
	fore(x,0,n){
		ll p=pa[x],res=-1;
		//cout<<"\n"<<x<<": "<<pa[x]<<" | "; imp(ofs[p]);
		if(SZ(ofs[p])==1)res=my[x]+*ofs[p].begin()+1;
		cout<<res<<" ";
	}
	cout<<"\n";
	return 0;
}

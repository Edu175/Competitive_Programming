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
const ll MAXN=1e4+5,MAXS=1005;

vector<pair<ll,char>> g[MAXN];
pair<ll,char> fa[MAXN];
string s;
ll dp[MAXN][MAXS][2];

vector<ll>ord;
void dfs(ll x){
	auto [f,c]=fa[x];
	for(auto [y,c]:g[x])if(y!=f){
		fa[y]={x,c};
		dfs(y);
	}
	ord.pb(x);
}
vector<vector<ll>> get(ll x){ // upd father
	auto [f,c]=fa[x];
	//push
	vector<vector<ll>>ret(SZ(s),vector<ll>(2));
	cout<<"get "<<x<<":\n";
	fore(j,0,SZ(s)){
		ll &res=dp[x][j][0];
		ret[j][0]=max(ret[j][0],res);
		if(j<SZ(s)-1){
			//dp[x][j+1][0]=max(dp[x][j+1][0],res);
			ret[j+1][0]=max(ret[j+1][0],ret[j][0]);
			if(c==s[j])ret[j+1][0]=max(ret[j+1][0],1+res);
		}
	}
	for(ll j=SZ(s)-1;j>=0;j--){
		ll &res=dp[x][j][1];
		cout<<j<<" "<<res<<"\n";
		ret[j][1]=max(ret[j][1],res);
		if(j){
			//dp[x][j-1][1]=max(dp[x][j-1][1],res);
			ret[j-1][1]=max(ret[j-1][1],ret[j][1]);
			if(c==s[j])ret[j-1][1]=max(ret[j-1][1],1+res);
		}
	}
	cout<<"get ";
	for(auto v:ret){
		cout<<v[0]<<","<<v[1]<<" ";
	}
	cout<<"\n";
	return ret;
}
ll ans=0;

void calc(ll x){
	ll res=0;
	cout<<x<<":\n";
	vector<ll> r0(SZ(s)),r1(SZ(s));
	for(auto [y,c]:g[x])if(y!=fa[x].fst){
		vector<vector<ll>> now=get(y);
		//push(y);
		fore(j,0,SZ(s)){
			ll ri0=now[j][0];
			ll ri1=now[j][1];
			cout<<x<<"--"<<y<<" "<<j<<": "<<r0[j]<<","<<r1[j]<<" "<<ri0<<","<<ri1<<": "<<res;
			res=max({res,r0[j]+ri1,r1[j]+ri0});
			r0[j]=max(r0[j],ri0);
			r1[j]=max(r1[j],ri1);
			cout<<" --> "<<res<<"\n";
		}
	}
	cout<<"end "<<x<<" "<<res<<"\n";
	ans=max(ans,res);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,n-1){
			ll u,v; char c; cin>>u>>v>>c; u--,v--;
			g[u].pb({v,c});
			g[v].pb({u,c});
		}
		cin>>s;
		fa[0]={-1,'.'};
		ans=0;
		fore(i,0,n+3)fore(j,0,SZ(s)+3)fore(k,0,2)dp[i][j][k]=0;
		dfs(0);
		//reverse(ALL(ord));
		for(auto x:ord){
			calc(x);
			for(auto [y,c]:g[x])if(y!=fa[x].fst){
				vector<vector<ll>> now=get(y);
				fore(j,0,SZ(s))fore(k,0,2){
					dp[x][j][k]=max(dp[x][j][k],now[j][k]);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

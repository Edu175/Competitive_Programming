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
ll fa[MAXN];
string s;
ll dp[MAXN][MAXS][2];
//ll dp2[MAXN][MAXS];

ll f(ll x, ll j, ll b){
	ll &res=dp[x][j][b];
	if(res!=-1)return res;
	res=0;
	for(auto [y,c]:g[x])if(y!=fa[x]){
		fa[y]=x;
		res=max(res,f(y,j,b));
		if(b==0&&j){
			res=max(res,f(x,j-1,b));
			if(c==s[j])res=max(res,1+f(y,j-1,b));
		}
		if(b==1&&j<SZ(s)-1){
			res=max(res,f(x,j+1,b));
			if(c==s[j])res=max(res,1+f(y,j+1,b));
		}
	}
	cout<<"f "<<x<<" "<<j<<" "<<b<<": "<<res<<"\n";
	return res;
}
ll f2(ll x, ll j){
	ll ans=0;
	ll r0=0,r1=0;
	cout<<x<<" "<<j<<":\n";
	for(auto [y,c]:g[x])if(y!=fa[x]){
		ll ri0=0,ri1=0;
		if(j){
			ri0=max(ri0,f(y,j,0));
			ri0=max(ri0,f(x,j-1,0));
			if(c==s[j])ri0=max(ri0,1+f(y,j-1,0));
		}
		if(j<SZ(s)-1){
			ri1=max(ri1,f(y,j,1));
			ri1=max(ri1,f(x,j+1,1));
			if(c==s[j])ri1=max(ri1,1+f(y,j+1,1));
		}
		cout<<y<<": "<<ri0<<","<<ri1<<" "<<r0<<","<<r1<<": "<<ans;
		ans=max({ans,r0+ri1,r1+ri0});
		r0=max(r0,ri0);
		r1=max(r1,ri1);
		cout<<" --> "<<ans<<"\n";
	}
	cout<<ans<<"\n\n";
	return ans;
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
		fa[0]=-1;
		fore(i,0,n+3)fore(j,0,SZ(s)+3)fore(k,0,2)dp[i][j][k]=0;
		fore(j,0,SZ(s)){
			f(0,j,0);
			cout<<"\n";
			f(0,j,1);
			cout<<"\n";
		}
		ll res=0;
		fore(i,0,n)fore(j,0,SZ(s)){
			res=max(res,f2(i,j));
		}
		cout<<res<<"\n";
	}
	return 0;
}

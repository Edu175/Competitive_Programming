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
const ll MAXM=1e5+5;

ll n,m,x;
ll a[10],vis[MAXM];
ll dp[MAXM];

ll f(ll i){
	if(i>x)return 0;
	ll &res=dp[i];
	if(res!=-1)return res;
	if(i==x)return res=1;
	if(vis[i])return res=0;
	fore(j,0,n)res=max(res,f(i+a[j]));
	return res;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	cin>>m;
	fore(i,0,m){
		ll x; cin>>x; vis[x]=1;
	}
	cin>>x;
	mset(dp,-1);
	if(f(0))cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

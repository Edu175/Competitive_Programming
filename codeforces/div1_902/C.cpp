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
const ll MAXN=2e5+5,K=19;

ll a[MAXN];

ll go[K][1ll<<K];
ll cy[MAXN],c[MAXN];
vector<ll>g[MAXN];

ll flag=1;
void dfs(ll x, ll w){
	c[x]=w;
	for(auto y:g[x]){
		if(!c[y])dfs(y,3-w);
		else if(c[x]!=w)flag=0;
	}
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i],a[i]--,g[a[i]].pb(i);
	fore(i,0,n)go[0][i]=a[i];
	fore(k,1,K)fore(i,0,n)go[k][i]=go[k-1][go[k-1][i]];
	fore(i,0,n)cy[go[K-1][i]]=1;
	fore(i,0,n)if(cy[i]&&SZ(g[i])>1){
		for(ll x=i,b=2;!c[x];x=a[x],b=3-b)c[x]=b;
	}
	fore(x,0,n){
		if(c[x])dfs(x,c[x]);
	}
	fore(x,0,n)if(!c[x])dfs(x,1);
	if(!flag){
		cout<<"-1\n";
		return 0;
	}
	fore(i,0,n)cout<<c[i]<<" ";;cout<<"\n";
	vector<ll>res;
	fore(i,0,n)if(c[i]==1)res.pb(a[i]+1);
	cout<<SZ(res)<<"\n";
	imp(res);
	return 0;
}

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

ll n,k;
ll a[MAXN],d[MAXN],vis[MAXN];
ll flag=1;
ll dfs(ll x){
	vis[x]=1;
	if(!vis[a[x]]){
		d[a[x]]=d[x]+1;
		dfs(a[x]);
	}
	else if(vis[x]==1){
		if(abs(d[x]-d[a[x]])+1!=k)flag=0;
	}
	vis[x]=2;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		fore(i,0,n)cin>>a[i],a[i]--;
		flag=0;
		fore(i,0,n){
			vis[i]=0;
			d[i]=0;
		}
		fore(x,0,n)if(!vis[x]){
			dfs(x);
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

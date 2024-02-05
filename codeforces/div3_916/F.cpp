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
const ll MAXN=2e5+5;

vector<ll> g[MAXN];
ll d[MAXN],c[MAXN];

void dfs(ll x){
	c[d[x]]++;
	for(auto y:g[x]){
		d[y]=d[x]+1;
		dfs(y);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			c[i]=0;
		}
		d[0]=0;
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		dfs(0);
		ll cnt=0,res=0;
		fore(i,0,n){
			if(!c[i])break;
			if(c[i]>=2)cnt+=c[i]-2,res++;
			else if(cnt)res++,cnt--;
		}
		res+=cnt/2;
		cout<<res<<"\n";
	}
	return 0;
}

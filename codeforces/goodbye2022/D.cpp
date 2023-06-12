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
const ll MOD=998244353,MAXN=1e5+5;
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
vector<ll> g[MAXN];
bool vis[MAXN];
ll e=0,m=0;
void dfs(ll x){
	vis[x]=1;
	m++;
	//bool ret=1;
	ll sl=0;
	for(auto i:g[x]){
		if(i==x)sl++;
		e++;
		if(!vis[i])dfs(i);
	}
	/*if(sl&&SZ(g[x])>1)ret=0;
	return ret;*/
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear(),vis[i]=0;
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)cin>>b[i],b[i]--;
		ll sl=0;
		fore(i,0,n){
			g[a[i]].pb(b[i]);
			g[b[i]].pb(a[i]);
			sl+=(a[i]==b[i]);
		}
		/*fore(i,0,n){
			cout<<i<<": ";
			imp(g[i]);
		}
		cout<<"\n";*/
		ll flag=1,c=0;
		fore(i,0,n){
			e=0,m=0;
			if(!vis[i]){
				/*bool f1=*/dfs(i);
				if(/*(!f1)||*/e/2>m)flag=0;
				//cout<<i<<": "/*<<f1<<" "*/<<e<<" "<<m<<"\n";
				c++;
			}
		}
		//cout<<sl<<" "<<c<<" "<<flag<<" ";
		if(!flag)cout<<"0\n";
		else{
			ll res=(fpow(2,c-sl)*fpow(n,sl))%MOD;
			cout<<res<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

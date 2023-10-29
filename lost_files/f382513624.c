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
const ll MAXN=105;

ll n;
ll flag=0;
vector<ll>ask(ll x){
	if(x!=1)cout<<x<<endl;
	if(x==n){
		string s; cin>>s;
		flag=1;
		return {};
	}
	ll k; cin>>k;
	vector<ll>r(k);
	fore(i,0,k)cin>>r[i];
	return r;
}
void say(ll x){
	cout<<x<<endl;
	ll k; cin>>k;
	fore(i,0,k){
		ll b; cin>>b;
	}
}
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	vector<ll>g=ask(x);
	if(flag)return;
	for(auto y:g)if(!vis[y]){
		dfs(y);
		if(flag)return;
		say(x);
	}
}

int main(){FIN;
	ll m; cin>>n>>m;
	dfs(1);
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

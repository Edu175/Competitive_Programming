#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MAXN=4005;
vector<ll> g[MAXN];
ll b[MAXN];
ll w[MAXN];
string s;
void dfs(ll v){
	if(s[v]=='W')w[v]=1,b[v]=0;
	if(s[v]=='B')w[v]=0,b[v]=1;
	for(auto i:g[v]){
		dfs(i);
		w[v]+=w[i];
		b[v]+=b[i];
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll p[n];
		fore(i,1,n)cin>>p[i],p[i]--, g[p[i]].pb(i);
		/*//CHEQUEAR VECINOS
		fore(i,0,n){
			cout<<i<<": ";
			for(auto j:g[i])cout<<j<<" ";
			cout<<"\n";
		}*/
		cin>>s;
		dfs(0);
		ll res=0;
		fore(i,0,n)if(b[i]==w[i])res++;
		cout<<res<<"\n";
		fore(i,0,n)g[i].clear();
	}
	return 0;
}

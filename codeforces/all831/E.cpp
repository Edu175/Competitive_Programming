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
const ll MAXN=1e5+5;
vector<ll> g[MAXN];
ll p[MAXN];
ll dp[MAXN][4];
ll f(ll x,ll b){
	ll &res=dp[x][b];
	if(res>=0)return res;
	ll sum=0, maxi=0;
	for(auto i:g[x]){
		if(!b)sum+=max(f(i,1),f(i,0));
		if(b)maxi=max(maxi,f(i,1));
	}
	/*if(b&&SZ(go)){
		sort(ALL(go));
		reverse(ALL(go));
		res=go[0].snd;
		for(auto i:g[x]){
			if(i!=go[0].snd)res+=f(i,0);
		}
		return res;
	}*/
	return res=max(sum,maxi+1);
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n+3)p[i]=-1;
	mset(dp,-1);
	fore(i,1,n){
		cin>>p[i];p[i]--;
		g[p[i]].pb(i);
	}
	cout<<max(f(0,0),f(0,1));
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

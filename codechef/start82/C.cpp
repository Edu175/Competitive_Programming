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
const ll MOD=1e9+7;
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> p(n),a(n);
		fore(i,0,n)cin>>p[i],p[i]--;
		fore(i,0,n)cin>>a[i];
		vector<ll>q;
		fore(i,0,n)q.pb(i);
		fore(i,0,n)q[i]=q[p[i]];
		vector<ll> vis(n),us;
		fore(i,0,n)vis[q[i]]=1;
		fore(i,0,n)if(vis[i]&&a[i])us.pb(a[i]);
		ll ind=0,flag=1;
		fore(i,0,n)ind+=(!a[i]&&!vis[i]);
		fore(i,1,SZ(us))if(us[i]!=us[i-1])flag=0;
		ind+=(!SZ(us));
		ll res=0;
		if(flag)res=fpow(m,ind);
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

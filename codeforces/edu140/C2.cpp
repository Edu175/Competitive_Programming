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
const ll MOD=998244353,MAXN=105;
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
ll a[MAXN][MAXN],vis[MAXN];
int main(){FIN;
	ll n; cin>>n;
	ll flag=1;
	ll u[n],d[n];
	fore(i,0,n){
		u[i]=i,d[i]=n;
		fore(j,i,n){
			cin>>a[i][j];
			if(a[i][j]==1)u[i]=j;
			if(a[i][j]==2)d[i]=min(d[i],j);
		}
	}
	fore(i,0,n){
		ll j=0;
		while(u[i]>=j)u[i]=max(u[i],u[j]),j++;
	}
	fore(i,0,n){
		fore(j,i,n)d[i]=min(d[i],d[j]);
	}
	fore(i,0,n)if(d[i]<=u[i])flag=0;
	imp(u);
	imp(d);
	ll c=1,m=0;
	set<ll>st;
	fore(i,0,n){
		if(vis[i])continue;
		fore(j,i,(d[i]==n?u[i]:d[i])+1)vis[j]=1;
		cout<<i<<" "<<(d[i]==n?u[i]:d[i])<<": "<<u[i]<<" "<<d[i]<<"\n";
		m++;
		c=c*(fpow(2,d[i]-u[i])-1+MOD)%MOD;
	}
	ll res=0;
	if(flag)res=(fpow(2,m)*c)%MOD;
	cout<<m<<" "<<c<<": "<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

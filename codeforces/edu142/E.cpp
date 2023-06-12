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

map<ll,ll> fact(ll x){ // SZ(v)<=14
	map<ll,ll>v;
	for(ll i=2; i*i<=x; i++){
		ll c=0;
		while(x%i==0)c++,x/=i;
		if(c)v[i]=c;
	}
	if(x>1)v[x]=1;
	return v;
}
vector<ii>m;
vector<ll>pr;
vector<ll> itov(ll x){
	vector<ll>res(SZ(m),0);
	fore(i,0,SZ(m))res[i]=x%(m[i].snd+1),x/=m[i].snd+1;
	return res;
}
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b;
		b=b*b,e>>=1;
	}
	return ret;
}
ll n;
ll dp[MAXN];
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m1,m2; cin>>n>>m1>>m2;
		map<ll,ll>mp=fact(m1);
		for(auto i:fact(m2))mp[i.fst]+=i.snd;
		m.clear();
		for(auto i:mp)m.pb(i);
		//for(auto i:m)cout<<i.fst<<","<<i.snd<<" "; cout<<"\n";
		pr.resize(SZ(m)+1);
		pr[0]=1;
		fore(i,1,SZ(m)+1)pr[i]=pr[i-1]*(m[i-1].snd+1);
		ll ans=0,q=0;
		fore(x,0,pr[SZ(m)]){
			ll &res=dp[x];
			vector<ll>pf=itov(x);
			ll d=1;
			fore(i,0,SZ(m))d*=fpow(m[i].fst,pf[i]);
			res=d;
			if(res>n)res=-1;
			fore(i,0,SZ(m))if(pf[i])res=max(res,dp[x-pr[i]]);
			if(d/res>n)res=-1;
			//cout<<x<<" "<<d<<": "; imp(pf); cout<<res<<"\n";
			if(res!=-1)ans^=d/res,q++;
		}
		cout<<q<<" "<<ans<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

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
const ll MOD=998244353;

/*map<ll,ll> operator+(map<ll,ll>mp1,map<ll,ll>mp2){
	map<ll,ll>res;
	for(auto i:mp1)res[i.fst]+=i.snd;
	for(auto i:mp2)res[i.fst]+=i.snd;
	return res;
}*/

vector<ll> fact(ll x){
	vector<ll>res;
	for(ll i=2; i*i<=x; i++){
		ll c=0;
		while(x%i==0){
			c++;
			x/=i;
		}
		if(c)res.pb(i);
	}
	if(x>1)res.pb(x);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll flag=1;
		fore(i,0,n-1)if(a[i]%a[i+1]!=0)flag=0;
		if(!flag){
			cout<<"0\n";
			continue;
		}
		/*map<ll,ll>pf[n+1];
		pf[n]={};
		for(ll i=n-1;i>=0;i--){
			pf[i]=pf[i+1]+fact(a[i]/a[i+1]);
		}*/
		ll res=1;
		fore(i,1,n){
			ll ran=m/a[i];
			ll add=0;
			vector<ll>unw=fact(a[i-1]/a[i]);
			ll bm=1ll<<SZ(unw);
			ll op=0;
			fore(b,1,bm){
				ll cp=1;
				fore(j,0,SZ(unw))if(b&(1ll<<j))cp*=unw[j];
				if(__builtin_popcountll(b)%2){
					op+=ran/cp;
				}
				else op-=ran/cp;
			}
			add=ran-op;
			res=(res*add)%MOD;
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

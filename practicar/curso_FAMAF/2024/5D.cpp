#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5;

ll cr[MAXN];
void init_sieve(){
	mset(cr,-1);
	fore(i,2,MAXN)if(cr[i]==-1)for(ll j=1ll*i*i;j<MAXN;j+=i)cr[j]=i;
}

map<ll,ll> fact(ll x){
	map<ll,ll>r;
	while(cr[x]!=-1){
		r[cr[x]]++;
		x/=cr[x];
	}
	if(x>1)r[x]++;
	return r;
}

int main(){FIN;
	init_sieve();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		map<ll,ll>mp;
		fore(i,0,n){
			ll x; cin>>x;
			for(auto [p,c]:fact(x))mp[p]+=c;
		}
		ll flag=1;
		for(auto i:mp)flag&=i.snd%n==0;//,cout<<i.fst<<","<<i.snd<<"\n";
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
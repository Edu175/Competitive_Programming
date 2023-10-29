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
map<ll,ll> fact(ll x){
	map<ll,ll>v;
	for(ll i=2; i*i<=x; i++){
		ll count=0;
		while(x%i==0){
			count++;
			x/=i;
		}
		if(count)v[i]+=count;
	}
	if(x>1)v[x]+=1;
	return v;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		map<ll,ll>mp;
		fore(i,0,n){
			cin>>a[i];
			map<ll,ll>mpi=fact(a[i]);
			for(auto i:mpi)mp[i.fst]+=i.snd;
		}
		vector<ll>e;
		for(auto i:mp)e.pb(i.snd);
		ll res=0;
		ll c=0;
		for(auto i:e){
			res+=i/2;
			c+=(i&1);
		}
		res+=c/3;
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

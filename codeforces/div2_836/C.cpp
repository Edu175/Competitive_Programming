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
vector<pair<ll,ll>> fact(ll x){
	vector<pair<ll,ll>>v;
	if(x==1)v.pb({1,0}); 
	for(ll i=2; i*i<=x; i++){
		ll count=0;
		while(x%i==0){
			count++;
			x/=i;
		}
		if(count)v.pb({i,count});
	}
	if(x>1)v.pb({x,1});
	sort(ALL(v));
	return v;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,x; cin>>n>>x;
		if((n%x)!=0){
			cout<<"-1\n";
			continue;
		}
		vector<ll>res(n);
		res[0]=x;
		fore(i,1,n){
			res[i]=i+1;
		}
		vector<ll>pos;
		vector<pair<ll,ll>>f=fact(n/x);
		ll j=x;
		for(auto i:f){
			while(i.snd--){
				pos.pb(j);
				j*=i.fst;
			}
		}
		pos.pb(j);
		//imp(pos);
		res[n-1]=1;
		fore(i,0,SZ(pos)-1){
			res[pos[i]-1]=pos[i+1];
		}
		imp(res);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

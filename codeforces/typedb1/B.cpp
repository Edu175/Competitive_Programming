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
	return v;
}
bool cmp(ii a, ii b){
	swap(a.fst,a.snd);
	swap(b.fst,b.snd);
	return a<b;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pair<ll,ll>>f=fact(n);
		sort(ALL(f),cmp);
		ll res=0;
		fore(i,0,SZ(f)){
			//cout<<i<<": "<<f[i].fst<<","<<f[i].snd<<": ";
			if(f[i].snd==0)continue;
			ll pr=f[i].fst;
			fore(j,i+1,SZ(f))pr*=f[j].fst,f[j].snd-=f[i].snd;//,cout<<j<<"="<<pr<<" ";
			res+=pr*f[i].snd;
			//cout<<": "<<f[i].snd<<" "<<pr*f[i].snd<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

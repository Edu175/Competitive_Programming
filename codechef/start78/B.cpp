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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		vector<pair<ll,ll>>v;
		fore(i,0,n)v.pb({a[i]+b[i],i});
		sort(ALL(v));
		ll id[n];
		fore(i,0,n)id[v[i].snd]=i;
		vector<ll>sp(n+1,0);
		fore(i,1,n+1)sp[i]=sp[i-1]+v[i-1].fst;
		ll res=0;
		fore(i,0,n){
			ll ki=k-a[i];
			if(ki<0)continue;
			ll lwb=lower_bound(ALL(sp),ki+1)-sp.begin();
			if(lwb>id[i])lwb=lower_bound(ALL(sp),ki+1+a[i]+b[i])-sp.begin()-1;
			res=max(res,lwb);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

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
		ll n,c; cin>>n>>c;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		vector<pair<ll,ll>>b;
		fore(i,0,n)b.pb({a[i]+min(i+1,n-i),i});
		sort(ALL(b));
		ll p[n]; fore(i,0,n)p[b[i].snd]=i;
		ll res=0;
		vector<ll> sp(n+1,0); fore(i,1,n+1)sp[i]=sp[i-1]+b[i-1].fst;
		fore(x,0,n){
			ll ci=c;
			ci-=a[x]+x+1;
			if(ci<0)continue;
			ll w=lower_bound(ALL(sp),ci+1)-sp.begin()-1; //last <= ci
			if(w-1<p[x]){
				res=max(res,w+1);
				continue;
			}
			ll cst=a[x]+min(x+1,n-x);
			w=lower_bound(ALL(sp),ci+cst+1)-sp.begin()-1;
			res=max(res,w);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

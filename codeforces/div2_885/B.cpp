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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll a[n];
		vector<ll>pos[k];
		fore(i,0,k)pos[i].pb(-1);
		fore(i,0,n)cin>>a[i],a[i]--,pos[a[i]].pb(i);
		fore(i,0,k)pos[i].pb(n);
		ll res=n;
		for(auto v:pos){
			vector<ll>d;
			fore(i,1,SZ(v))d.pb(v[i]-v[i-1]-1);
			sort(ALL(d));
			ll resi=max(d.back()/2,d[SZ(d)-2]);
			res=min(res,resi);
		}
		cout<<res<<"\n";
	}
	return 0;
}

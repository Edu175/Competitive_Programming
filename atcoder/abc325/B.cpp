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
	ll n; cin>>n;
	ii a[n];
	ll c[n];
	ll dis[n][24]={};
	fore(i,0,n){
		cin>>c[i];
		ll x; cin>>x;
		a[i].fst=9-x,a[i].snd=a[i].fst+9;
		fore(j,a[i].fst,a[i].snd){
			ll t=(j+24)%24;
			dis[i][t]=1;
		}
	}
	ll res=0;
	fore(h,0,24){
		ll resi=0;
		fore(i,0,n)if(dis[i][h]==1)resi+=c[i];
		res=max(res,resi);
	}
	cout<<res<<"\n";
	return 0;
}

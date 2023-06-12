#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[n];
		ll oc[n];
		fore(i,0,n)cin>>a[i],oc[i]=0;
		pair<ll,ll> ed[m];
		fore(i,0,m){
			cin>>ed[i].fst>>ed[i].snd;
			ed[i].fst--,ed[i].snd--;
			oc[ed[i].fst]++;
			oc[ed[i].snd]++;
		}
		if(m%2==0){
			cout<<0<<"\n";
			continue;
		}
		ll res=1e9+5;
		fore(i,0,n){
			if(oc[i]%2)res=min(res,a[i]);
		}
		fore(i,0,m){
			ll &x=ed[i].fst, &y=ed[i].snd;
			if(oc[x]%2==0&&oc[y]%2==0)res=min(res,a[x]+a[y]);
		}
		//imp(oc);
		pres;
	}
	return 0;
}

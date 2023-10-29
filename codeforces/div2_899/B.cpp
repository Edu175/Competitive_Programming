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
		ll n; cin>>n;
		vector<ll> a[n];
		vector<ll>esta(55);
		fore(i,0,n){
			ll m; cin>>m; a[i].resize(m);
			fore(j,0,m)cin>>a[i][j],esta[a[i][j]]=1;
		}
		ll res=0;
		fore(v,0,55){
			if(!esta[v])continue;
			vector<ll> is(55);
			fore(i,0,n){
				ll flag=0;
				fore(j,0,SZ(a[i]))if(a[i][j]==v)flag=1;
				if(flag)continue;
				fore(j,0,SZ(a[i]))is[a[i][j]]=1;
			}
			ll resi=0;
			for(auto i:is)resi+=i;
			res=max(res,resi);
		}
		cout<<res<<"\n";
	}
	return 0;
}

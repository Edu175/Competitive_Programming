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
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		map<ll,vector<ll>>mp;
		fore(i,0,n)mp[a[i]].pb(i);
		vector<ll>b(n);
		ll did=0;
		for(auto [sus,v]:mp){
			for(auto i:v)b[i]=1;
			if(SZ(v)>1){
				if(!did)b[v[1]]=2,did=1;
				else b[v[1]]=3,did=2;
			}
		}
		if(did<2)cout<<"-1\n";
		else {
			imp(b);
		}
	}
	return 0;
}

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
		vector<ll>l,r;
		map<ll,ll>mp;
		fore(i,0,n){
			if(mp[a[i]]==0)l.pb(i);
			mp[a[i]]++;
		}
		mp.clear();
		for(ll i=n-1;i>=0;i--){
			if(mp[a[i]]==0)r.pb(i);
			mp[a[i]]++;
		}
		ll res=0;
		sort(ALL(l)); sort(ALL(r));
		//imp(l);
		//imp(r);
		for(auto i:r){
			res+=lower_bound(ALL(l),i+1)-l.begin();
		}
		cout<<res<<"\n";
		//cout<<"\n";
	}
	return 0;
}

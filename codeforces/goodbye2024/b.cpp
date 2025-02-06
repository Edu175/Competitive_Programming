#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii>a(n);
		vector<ll> un;
		map<ll,ll>mp;
		fore(i,0,n){
			cin>>a[i].fst>>a[i].snd;
			if(a[i].fst==a[i].snd)un.pb(a[i].fst),mp[a[i].fst]++;
			a[i].snd++;
		}
		sort(ALL(un));
		auto _un=un;
		un.clear();
		for(auto i:_un)if(!SZ(un)||i!=un.back())un.pb(i);
		string res(n,'0');
		fore(i,0,n){
			auto [l,r]=a[i];
			ll q=lower_bound(ALL(un),r)-lower_bound(ALL(un),l);
			if(r-l==1){
				if(mp[l]==1)res[i]++;
			}
			else if(q<r-l)res[i]++;
		}
		cout<<res<<"\n";
	}
	return 0;
}

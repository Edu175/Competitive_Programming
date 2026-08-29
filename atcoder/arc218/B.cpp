#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		map<ll,ll> mp;
		fore(i,0,n)cin>>a[i],mp[a[i]]++;
		sort(ALL(a));
		ll acum=0,po=0,t=0;
		while(po<n&&a[po]-acum<2){
			if(a[po]-acum==1)acum++;
			else {
				if(mp[a[po]]>=2)break;
				po++;
			}
			t^=1;
		}
		if(po==n)t^=1;
		cout<<vector<string>({"Alice\n","Bob\n"})[t];
	}
	return 0;
}

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
		ll n,k; cin>>n>>k;
		vv a(n);
		map<ll,ll>mp;
		fore(i,0,n)cin>>a[i],mp[a[i]]++;
		vv b;
		for(auto i:mp)b.pb(i.snd);
		sort(ALL(b));
		ll res=1;
		fore(i,0,SZ(b)){
			if(k<b[i]){res=SZ(b)-i;break;}
			k-=b[i];
		}
		cout<<res<<"\n";
	}
	return 0;
}

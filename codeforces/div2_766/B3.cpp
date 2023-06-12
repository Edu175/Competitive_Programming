#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m;cin>>n>>m;ll a[n][m];
		ll res=n/2+m/2;
		vector<pair<ll,ll>> mid; 
		mid.pb({n/2,m/2});
		if(n%2==0)mid.pb({n/2-1,m/2});
		if(m%2==0)mid.pb({n/2,m/2-1});
		if(n%2==0&&m%2==0)mid.pb({n/2-1,m/2-1});
		vector<ll> d(n/2+m/2+1);
		set<ll>st;
		fore(i,0,n){
			fore(j,0,m){
				ll mini=100005;
				for(auto h:mid)mini=(min(mini,abs(h.fst-i)+abs(h.snd-j)));
				d[mini]++;
			}
		}
		fore(i,1,n/2+m/2+1)d[i]+=d[i-1];
		ll x=0;
		fore(i,0,n*m){
			if(i>=d[x]){
				res++;
				if(x<=n/2+m/2)x++;
			}
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	 return 0;
}

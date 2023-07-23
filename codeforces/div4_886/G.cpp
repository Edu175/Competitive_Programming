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
		ii a[n];
		map<ii,ll>mp;
		ll res=0;
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			a[i]={x,y};
			mp[{0,x}]++;
			mp[{1,y}]++;
			mp[{2,x-y}]++;
			mp[{3,y+x}]++;
			//cout<<x<<","<<y<<": "<<x-y<<" "<<x+y<<"\n";
		}
		fore(i,0,n){
			ll x=a[i].fst,y=a[i].snd;
			res+=mp[{0,x}]-1;
			res+=mp[{1,y}]-1;
			res+=mp[{2,x-y}]-1;
			res+=mp[{3,y+x}]-1;
		}
		cout<<res<<"\n";
	}
	return 0;
}

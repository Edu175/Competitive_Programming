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
		if(k==0){
			vv res={3, 4, 8, 7, 2, 1, 5, 6};
			if(n<SZ(res)){
				cout<<"-1\n";
				continue;
			}
			fore(i,SZ(res)+1,n+1)res.pb(i);
			imp(res);
			continue;
		}
		if(k==1){
			if(n==1){
				cout<<"1\n";
				continue;
			}
			vv res={4,1,3,5,2};
			if(n<SZ(res)){
				cout<<"-1\n";
				continue;
			}
			fore(i,SZ(res)+1,n+1)res.pb(i);
			imp(res);
			continue;
		}
		vv res;
		for(ll i=k;i>0;i--)res.pb(i);
		fore(i,k+1,n+1)res.pb(i);
		imp(res)
	}
	return 0;
}

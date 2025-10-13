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

ll opu(ll n, ll k){
	ll all=(1ll<<k)-1;
	ll s=(~n)&all;
	return s;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r; r++;
		vv res(r-l,-1),used(r-l+1);
		for(ll k=33;k>=0;k--){
			if(k<5){
				cout<<"ronda "<<k<<"\n";
				imp(res)
				cout<<endl;
			}
			fore(i,l,r)if(res[i-l]==-1){
				ll j=opu(i,k);
				if(j<l||j>=r)continue;
				if(used[j-l])continue;
				cout<<"assigned "<<i<<" "<<j<<"\n";
				res[i-l]=j;
				used[j-l]=1;
			}
		}
		ll tot=0;
		fore(i,l,r)tot+=(res[i-l]|i);
		cout<<tot<<"\n";
		imp(res)
	}
	return 0;
}

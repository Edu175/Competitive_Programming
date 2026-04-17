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

ll lcm(vv a){
	ll m=1;
	for(auto i:a)m=lcm(m,i);
	return m;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		vv nums(3);
		fore(i,0,3)cin>>nums[i];
		vv res(3);
		ll m; cin>>m;
		fore(i,0,3){
			swap(nums[0],nums[i]);
			ll a=nums[0];
			ll b=nums[1];
			ll c=nums[2];
			
			auto &cur=res[i];
			cur=6*(m/a);
			cur-=3*(m/lcm(a,b)+m/lcm(a,c));
			cur+=2*(m/lcm({a,b,c}));
			
			swap(nums[0],nums[i]);
		}
		imp(res)
	}
	return 0;
}

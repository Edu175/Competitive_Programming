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
	ll n,A,B; cin>>n>>A>>B;
	if(A*B<n || A+B-1>n){
		cout<<"-1\n";
		return 0;
	}
	vv a;
	ll fal=B;
	fore(i,0,B){
		fal--;
		for(ll y=-i,cnt=0;cnt<A;y+=B,cnt++){
			if(cnt&&SZ(a)+fal>=n)break;
			a.pb(y);
		}
	}
	vv vals=a; sort(ALL(vals));
	assert(unique(ALL(vals))==vals.end());
	auto get_idx=[&](ll v){return lower_bound(ALL(vals),v)-vals.begin();};
	fore(i,0,n){
		ll v=get_idx(a[i]);
		cout<<v+1<<" ";
	}
	cout<<"\n";
	return 0;
}

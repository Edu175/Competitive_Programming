#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {cerr<<"{ ";for(auto i:v)cerr<<i+1<<", "; cerr<<"}\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
vv mv(vv y, ll i){
	rotate(y.begin(),y.begin()+i,y.begin()+i+1);
	rotate(y.begin()+i+1,y.begin()+i+2,y.end());
	return y;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		vv ops;
		auto mop=[&](ll i){
			assert(i>=0&&i<n-1);
			a=mv(a,i);
			ops.pb(i);
		};
		ll bad=0;
		for(ll x=n-2;x>=0;x--){
			ll p=find(ALL(a),x)-a.begin();
			if(p<n-1)mop(p);
			else {
				if(x){
					mop(n-2-x);
					mop(n-2);
					mop(0);
					assert(a[0]==x);
				}
				else {
					if(n%2==0)bad=1;
					else {
						mop(0);
						mop(n-2);
						fore(_,0,n-3)mop(1);
					}
				}
			}
		}
		if(bad){
			cout<<"-1\n";
			continue;
		}
		assert(SZ(ops)<=4*n);
		vv id(n); iota(ALL(id),0); assert(a==id);
		cout<<SZ(ops)<<"\n";
		for(auto i:ops)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}

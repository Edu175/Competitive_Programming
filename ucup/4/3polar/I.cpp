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
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)cin>>b[i],b[i]--;
		vector<ii> ret;
		auto mop=[&](ll i, ll j){
			ret.pb({i,j});
			swap(a[i],a[j]);
		};
		ll fg=1;
		fore(v,0,n){
			ll p=find(ALL(a),v)-a.begin();
			ll q=find(ALL(b),v)-b.begin();
			if(p>q){fg=0;break;}
			vv pos;
			ll mn=n+5;
			for(ll i=q;i>p;i--)if(a[i]>v){
				if(a[i]<mn)pos.pb(i),mn=a[i];
			}
			reverse(ALL(pos));
			for(auto i:pos){
				mop(p,i);
				p=i;
			}
			assert(p==q);
		}
		if(!fg){
			cout<<"NO\n";
			continue;
		}
		assert(a==b);
		cout<<"YES\n";
		cout<<SZ(ret)<<"\n";
		for(auto [i,j]:ret)cout<<i+1<<" "<<j+1<<"\n";
	}
	return 0;
}

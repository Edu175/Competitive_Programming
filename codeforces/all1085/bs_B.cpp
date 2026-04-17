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
		ll n,m,l; cin>>n>>m>>l;
		vv a(n),is(l);
		fore(i,0,n)cin>>a[i],a[i]--,is[a[i]]=1;
		auto can=[&](ll x, ll dbg=0)->bool {
			vv b(m);
			b[0]=x;
			for(ll i=l-1;i>=0;i--){
				if(dbg){cerr<<i<<": "; imp(b);}
				if(is[i]){
					ll mn=min_element(ALL(b))-b.begin();
					if(b[mn]!=0)return 0;
					ll nmx=*max_element(ALL(b));
					b[mn]=nmx;
				}
				ll mx=max_element(ALL(b))-b.begin();
				if(b[mx]==0)return 1;
				b[mx]--;
			}
			ll fg=1;
			for(auto i:b)fg&=i<=0;
			return fg;
		};
		ll lo=0,hi=l+5;
		while(hi-lo>1){
			ll mid=(lo+hi)/2;
			if(can(mid))lo=mid;
			else hi=mid;
		}
		ll res=lo;
		can(18,1);
		cout<<res<<"\n";
	}
	return 0;
}

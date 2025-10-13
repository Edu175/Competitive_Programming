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
const ll MAXV=2e5+5;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,y; cin>>n>>y;
		vv oc(MAXV);
		fore(i,0,n){
			ll x; cin>>x;
			oc[x]++;
		}
		vv sp(SZ(oc)+1);
		fore(i,0,SZ(oc))sp[i+1]=sp[i]+oc[i];
		auto cost=[&](ll x){
			ll res=0;
			// if(x<5)cout<<"\ncost "<<x<<":\n";
			fore(v,1,MAXV){
				ll l=(v-1)*x,r=v*x;
				l++,r++;
				if(l>=MAXV)break;
				r=min(r,MAXV);
				ll c=sp[r]-sp[l];
				res+=v*c;
				ll q=max(c-oc[v],0ll);
				res-=y*q;
				// if(x<5&&c)cout<<v<<" "<<c<<": "<<q<<"\n";
			}
			return res;
		};
		ll res=-1e18;
		fore(x,2,MAXV)res=max(res,cost(x));
		cout<<res<<"\n";
	}
	return 0;
}

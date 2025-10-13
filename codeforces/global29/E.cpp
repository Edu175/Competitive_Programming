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
		ll n,q; cin>>n>>q;
		vv a(n);
		const ll B=35;
		fore(i,0,n)cin>>a[i];
		
		vector<ll> need(B),extra(B);
		
		fore(p,0,B){ // last bit on )
			auto &ex=extra[p];
			auto &cost=need[p];
			vv vis(n);
			for(ll j=p-1;j>=0;j--){
				ll all=(1ll<<j)-1;
				ll ind=-1,mx=0,fg=0;
				fore(i,0,n)if(!vis[i]){
					ll v=a[i]&all;
					fg|=a[i]>>j&1;
					if(v>mx)ind=i,mx=v;
				}
				ll cur=0;
				if(!fg){
					cur=(1ll<<j)-mx;
					if(ind!=-1)vis[ind]=1;
				}
				// if(p<5)cout<<j<<": "<<fg<<" "<<ind<<" "<<mx<<"\n";
				cost+=cur;
			}
			fore(j,p,B){
				ll hay=0;
				fore(i,0,n)hay|=a[i]>>j&1;
				ex+=hay;
			}
			ex+=p;
			// if(p<7)cout<<p<<": "<<cost<<" "<<ex<<"\n";
		}
		
		while(q--){
			ll k; cin>>k;
			ll res=0;
			fore(p,0,B)if(k>=need[p])res=max(res,extra[p]);
			cout<<res<<"\n";
		}
	}
	return 0;
}

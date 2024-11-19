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
		ll n,m,kdjsgf; cin>>n>>m>>kdjsgf;
		vector<pair<ii,ll>>ev;
		fore(i,0,n){
			ll l,r; cin>>l>>r;
			ev.pb({{l,r-l+2},1});
		}
		fore(i,0,m){
			ll x,v; cin>>x>>v;
			ev.pb({{x,v},0});
		}
		sort(ALL(ev));
		priority_queue<ll>pq;
		ll po=1,flag=1,res=0;
		for(auto [pa,ty]:ev){
			if(ty){
				while(po<pa.snd){
					if(!SZ(pq)){
						flag=0;
						break;
					}
					po+=pq.top(); pq.pop();
					res++;
				}
			}
			else pq.push(pa.snd);
		}
		if(!flag)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	return 0;
}

#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=(b)-1,jet=a;i>=jet;--i)
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
		ll n,m; cin>>n>>m;
		vv a(n);
		map<ll,ll> mp;
		fore(i,0,n)cin>>a[i],mp[a[i]]++;
		vector<vv> bu(n+1);
		for(auto i:mp)bu[i.snd].pb(i.fst);
		for(auto &v:bu)reverse(ALL(v));
		
		vv ids;
		fore(i,1,n+1)if(SZ(bu[i]))ids.pb(i);
		
		vector<array<ll,4>> eds;
		auto agr=[&](ll x, ll y){
			eds.pb({mp[x],mp[y],x,y});
		};
		fore(i,0,m){
			ll x,y; cin>>x>>y;
			agr(x,y);
			agr(y,x);
		}
		for(auto i:mp)agr(i.fst,i.fst);
		
		sort(ALL(eds));
		reverse(ALL(eds));
		
		ll res=0;
		ll po=0;
		forr(id0,0,SZ(ids)){
			ll ci=ids[id0];
			auto &u=bu[ci];
			
			forr(id1,0,SZ(ids)){
				ll cj=ids[id1];
				auto &v=bu[cj];
				vector<ii> cur;
				while(po<SZ(eds)&&eds[po][0]==ci&&eds[po][1]==cj){
					cur.pb({eds[po][2],eds[po][3]});
					po++;
				}
				// cerr<<"\n\nbuckets "<<ci<<" "<<cj<<"\n";
				// imp(u)
				// imp(v)
				// cout<<"cur: ";
				// for(auto [i,j]:cur)cout<<i<<","<<j<<" ";;cout<<"\n";
				
				ll cand=0;
				ll p=0; // of cur
				for(auto x:u)for(auto y:v){
					ii me={x,y};
					while(p<SZ(cur)&&cur[p]>me)p++;
					if(p==SZ(cur)||cur[p]!=me){
						cand=max(cand,x+y);
						// cerr<<"cand "<<x<<" "<<y<<": "<<cand<<"\n";
						break;
					}
				}
				res=max(res,cand*(ci+cj));
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}

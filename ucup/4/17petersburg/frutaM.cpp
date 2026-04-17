#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(a) {for(auto i:a)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef short ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll a,b,m; cin>>a>>b>>m;
		ll tam=2*m;
		vector<vv> has(tam);
		vv cb(tam,b),ca(tam,a);
		vector<ii> rans;
		fore(i,0,m){
			ll ty,l,r; cin>>ty>>l>>r; l--;
			if(ty==2){
				fore(j,l,r)ca[j]--;
				continue;
			}
			rans.pb({l,r});
		}
		sort(ALL(rans),[&](ii a, ii b){return a.snd-a.fst>b.snd-b.fst;});
		m=SZ(rans);
		fore(i,0,m){
			auto &[l,r]=rans[i];
			fore(j,l,r)has[j].pb(i);
		}
		vv vis(m);
		vv mnas(m),mnbs(m);
		fore(i,0,m){
			auto &mna=mnas[i];
			auto &mnb=mnbs[i];
			auto [l,r]=rans[i];
			mna=ca[l];
			mnb=cb[l];
			fore(j,l,r){
				mna=min(mna,ca[j]);
				mnb=min(mnb,cb[j]);
			}
		}
		fore(_,0,m){
			ll who=-1; ii val={-1,-1};
			fore(i,0,m)if(!vis[i]){
				ii cur={min(mnas[i],mnbs[i]),max(mnas[i],mnbs[i])};
				if(who==-1||cur<val)who=i,val=cur;
			}
			assert(who!=-1);
			vis[who]=1;
			auto [l,r]=rans[who];
			ll don=mnas[who]<mnbs[who]; // voy al min mas grande
			cout<<"uso "<<l+1<<","<<r<<" en "<<(don?"b":"a")<<"\n";
			fore(j,l,r){
				auto &p=(don?cb[j]:ca[j]); p--;
				for(auto i:has[j])if(!vis[i]){
					auto &cu=(don?mnbs[i]:mnas[i]);
					cu=min(cu,p);
				}
			}
			imp(ca)
			imp(cb)
		}
		ll good=1;
		fore(i,0,tam)good&=min(ca[i],cb[i])>=0;
		if(good)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
// uso 7,16 en b
// 1 1 1 1 1 1 2 2 2 2 2 1 1 1 2 2 
// 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 
// uso 1,8 en a
// 0 0 0 0 0 0 1 1 2 2 2 1 1 1 2 2 
// 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 
// uso 6,11 en b
// 0 0 0 0 0 0 1 1 2 2 2 1 1 1 2 2 
// 2 2 2 2 2 1 0 0 0 0 0 1 1 1 1 1 
// uso 7,12 en a
// 0 0 0 0 0 0 0 0 1 1 1 0 1 1 2 2 
// 2 2 2 2 2 1 0 0 0 0 0 1 1 1 1 1 
// uso 11,15 en a
// 0 0 0 0 0 0 0 0 1 1 0 -1 0 0 1 2 
// 2 2 2 2 2 1 0 0 0 0 0 1 1 1 1 1 
// No

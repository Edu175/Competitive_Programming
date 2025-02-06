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
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		// INDEX 1 !!!
		ll n,m,q; cin>>n>>m>>q;
		vector<ii>ran;
		ran.pb({m,m});
		auto intersect=[&](){
			sort(ALL(ran));
			vector<ii>rani;
			ll l=-1,r=-1;
			fore(i,0,SZ(ran)){
				if(r+1>=ran[i].fst)r=ran[i].snd;
				else {
					if(r!=-1)rani.pb({l,r});
					l=ran[i].fst;
					r=ran[i].snd;
				}
			}
			if(r!=-1)rani.pb({l,r});
			swap(ran,rani);
		};
		ll did=0;
		auto extend=[&](ii a, ll p)->ii{
			auto [l,r]=a;
			if(l==r&&l==p){did=1;return {-1,-1};};
			if(l<=p&&p<=r){did=1;return a;};
			if(p<l)l--;
			if(p>r)r++;
			return {l,r};
		};
		// impr(ran)
		fore(i,0,q){
			ll p; cin>>p;
			vector<ii>rani;
			did=0;
			fore(i,0,SZ(ran)){
				auto nue=extend(ran[i],p);
				if(nue.fst!=-1)rani.pb(nue);
			}
			swap(ran,rani);
			if(did)ran.pb({1,1}),ran.pb({n,n});
			intersect();
			ll res=0;
			for(auto [l,r]:ran)res+=r-l+1;
			// impr(ran)
			cout<<res<<" ";
			// cout<<"\n\n";
		}
		cout<<"\n";
	}
	return 0;
}

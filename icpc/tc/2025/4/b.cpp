#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv deg(n,3);
		ll cnt=0;
		vector<vv> rev;
		map<ii,ll> id; // x,y, which
		auto addeame=[&](ll i, ll x, ll w){
			ll idx;
			if(id.count({x,w}))idx=id[{x,w}];
			else id[{x,w}]=idx=cnt++,rev.pb({});
			rev[idx].pb(i);
			// cout<<"added "<<idx<<" "<<i<<"\n";
		};
		fore(i,0,n){
			ll x,y,z; cin>>x>>y>>z;
			addeame(i,x,0);
			addeame(i,y,1);
			addeame(i,z,2);
		}
		vector<ii> vec;
		// priority_queue<ii>pq;
		// auto putpq=[&](ll idx){pq.push({-SZ(rev[idx]),idx});};
		auto putvec=[&](ll idx){vec.pb({SZ(rev[idx]),idx});};
		fore(idx,0,cnt)putvec(idx);
		sort(ALL(vec));
		vv ans(n);
		ll pts=n,po=0;
		// for(auto i:vec)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		fore(k,1,n+1){
			// cout<<"k "<<k<<"\n";
			while(po<SZ(vec)&&vec[po].fst<k){
				auto [sz,idx]=vec[po++];
				// if(sz!=SZ(rev[idx]))continue;
				// cout<<"chau plano "<<idx<<"\n";
				for(auto i:rev[idx]){
					if(!(--deg[i]))pts--;//,cout<<"out "<<i<<"\n";
					// cout<<i<<" "<<deg[i]<<"\n";
				}
			}
			cout<<n-pts<<" ";
			// cout<<"\n\n";
		}
		cout<<"\n";
	}
	return 0;
}
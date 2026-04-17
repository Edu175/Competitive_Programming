#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";;cout<<endl;}
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e10;
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,ex; cin>>n>>ex;
		vv pos(n),w(n);
		set<ii>st;
		map<ll,ll>id;
		vector<pair<ii,ii>>a; // {start x coord, i} {l,r}
		ll ori=0,mn=INF,mx=0,mnl=INF;
		fore(i,0,n){
			ll l,d,r,u; cin>>l>>d>>r>>u;
			w[i]=r-l;
			a.pb({{l,i},{d,u}});
			ori=max(ori,r);
			mn=min(mn,d);
			mnl=min(mnl,l);
			mx=max(mx,u);
		}
		ori-=mnl;
		sort(ALL(a));
		auto add=[&](ll l, ll r, ll i){
			// cout<<"\nadd "<<l<<","<<r<<" "<<i<<"\n";
			// impr(st)
			auto &res=pos[i]; // dsp +=ex
			auto it=st.upper_bound({l,INF});
			ll did=0;
			auto actu=[&](ll idx){
				res=max(res,pos[idx]+w[idx]);
				// res=max(res,pos[idx]+ex);
				did=1;
			};
			if(it!=st.begin()){
				auto [s,e]=*prev(it);
				if(s<=l&&l<e){
					auto idx=id[s];
					actu(idx);
					st.erase(prev(it));
					if(s<l)st.insert({s,l});
				}
			}
			auto fin=st.upper_bound({r-1,INF});
			if(fin!=st.begin()){
				auto [s,e]=*prev(fin);
				if(s<=r-1&&r-1<e){
					auto idx=id[s];
					actu(idx);
					st.erase(prev(fin));
					if(r<e)st.insert({r,e}),id[r]=idx;
				}
			}
			vector<set<ii>::iterator>pop;
			// impr(st)
			for(auto it=st.upper_bound({l,INF});it!=st.end()&&it->fst<r;it++){//it=st.erase(it)){
				auto [s,e]=*it;
				auto idx=id[s];
				actu(idx);
				pop.pb(it);
			}
			for(auto i:pop)st.erase(i);
			if(did)res+=ex;
			st.insert({l,r});
			id[l]=i;
		};
		ll ans=0;
		for(auto [fst,snd]:a){
			auto [skjdf,i]=fst;
			auto [l,r]=snd;
			add(l,r,i);
			ans=max(ans,pos[i]+w[i]);
		}
		// cout<<mnl<<" mnl\n";
		// cout<<ori<<" "<<ans<<"\n";
		// cout<<mn<<" "<<mx<<"\n";
		// imp(pos)
		ll dif=ori-ans;
		ll res=dif*(mx-mn);
		cout<<max(res,0ll)<<"\n";
	}
	return 0;
}


/*
input:
1


6 4
2 5 4 11
2 14 6 17
7 10 10 16
9 4 16 7
11 11 16 14
18 4 20 18


output:
2 mnl
18 26
4 18
0 0 8 6 15 24 
-112

*/
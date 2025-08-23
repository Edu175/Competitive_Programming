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
		ll n,k; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll cost=0;
		set<ii> st={{0,0}};
		ll inf=n*n+100;
		
		auto cst=[&](auto it){
			return (it->snd-it->fst+k-1)/k;
		};
		
		auto ch=[&](auto &it, ll l, ll r){
			cost-=cst(it);
			st.erase(it);
			it=st.insert({l,r}).fst;
			cost+=cst(it);
		};
		
		auto agr=[&](ll p){
			// atras
			auto it=st.upper_bound({p,inf});
			it--;
			ll e=it->snd;
			if(p<=e)return;
			if(p-e<=k)ch(it,it->fst,p);
			else it=st.insert({p,p}).fst;
			
			// adelante
			while(it!=prev(st.end())){
				auto nit=next(it);
				if(nit->fst-it->snd<=k){
					ll e=nit->snd;
					cost-=cst(nit);
					st.erase(nit);
					ch(it,it->fst,e);
				}
				else break;
			}
		};
		auto query=[&](){
			return cost+SZ(st)-1;
		};
		fore(i,0,n){
			agr(a[i]);
			cout<<"\n\nst: ";
			for(auto i:st)cout<<i.fst<<","<<i.snd<<" ";
			cout<<": "<<cost<<"\n";
			cout<<query()<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

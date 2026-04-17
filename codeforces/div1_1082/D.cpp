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
const ll INF=1e18;

ll cu(ll z){return z*(z+1)/2;}
ll cu(ii a){
	ll z=a.snd-a.fst;
	return cu(z);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		vector<set<ll>> pos(n);
		vv nums(n+3);
		vector<set<ii>> sts(n+3);
		set<ii> bst;
		
		auto add=[&](ll d, ll p, ll c){
			auto &st=sts[d];
			auto &num=nums[d];
			st.insert({p,p+1});
			num+=cu(1);
			bst.insert({d,c});
			auto mergeIf=[&](auto l, auto r){
				if(l->snd!=r->fst)return;
				ii now={l->fst,r->snd};
				num-=cu(*l)+cu(*r);
				st.erase(l); st.erase(r);
				
				num+=cu(now);
				st.insert(now);
			};
			auto it=st.lower_bound({p,-1});
			if(next(it)!=st.end())mergeIf(it,next(it));
			it=st.lower_bound({p,-1});
			if(it!=st.begin())mergeIf(prev(it),it);
		};
		
		auto rem=[&](ll d, ll p, ll c){
			auto &st=sts[d];
			auto &num=nums[d];
			bst.erase({d,c});
			auto it=prev(st.upper_bound({p,INF}));
			auto par=*it;
			st.erase(it);
			
			num-=cu(par);
			ii nowl={par.fst,p};
			if(nowl.snd-nowl.fst>0)num+=cu(nowl),st.insert(nowl);
			
			ii nowr={p+1,par.snd};
			if(nowr.snd-nowr.fst>0)num+=cu(nowr),st.insert(nowr);
		};
		
		fore(i,0,n)pos[a[i]].insert(i);
		
		auto pon=[&](ll c){
			auto &s=pos[c];
			if(!SZ(s))return;
			ii pa={*s.begin(),*s.rbegin()};
			ll p=pa.fst,d=pa.snd-p;
			add(d,p,c);
		};
		
		auto sac=[&](ll c){
			auto &s=pos[c];
			if(!SZ(s))return;
			ii pa={*s.begin(),*s.rbegin()};
			ll p=pa.fst,d=pa.snd-p;
			rem(d,p,c);
		};
		
		fore(c,0,n)pon(c);
		
		// cout<<"d=4 "<<nums[4]<<": ";
		// impr(sts[4]);

		while(q--){
			ll i,v; cin>>i>>v; i--,v--;
			sac(a[i]);
			pos[a[i]].erase(i);
			pon(a[i]);
			
			a[i]=v;
			
			sac(a[i]);
			pos[a[i]].insert(i);
			pon(a[i]);
			
			// cout<<"d=4 "<<nums[4]<<": ";
			// impr(sts[4]);
			
			ll d=bst.rbegin()->fst;
			cout<<d<<" ";
			ll res=0;
			if(d)res=nums[d];
			cout<<res<<"\n";
		}
	}
	return 0;
}

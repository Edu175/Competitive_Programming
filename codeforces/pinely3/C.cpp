#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>l(n),r(n),c(n);
		set<ii>st;
		fore(i,0,n)cin>>l[i],st.insert({l[i],1});
		fore(i,0,n)cin>>r[i],st.insert({r[i],0});
		fore(i,0,n)cin>>c[i];
		sort(ALL(c)); reverse(ALL(c));
		priority_queue<pair<ll,ii>>pq;
		for(auto it=st.begin();it!=prev(st.end());it++){
			ii a=*it,b=*next(it);
			if(a.snd==1&&b.snd==0)pq.push({a.fst-b.fst,a});
		}
		ll res=0;
		fore(i,0,n){
			auto [v,a]=pq.top(); pq.pop(); v=-v;
			res+=v*c[i];
			auto it=st.lower_bound(a);
			st.erase(++it);
			st.erase(a);
			it=st.lower_bound(a);
			if(it!=st.begin()){
				--it;
				a=*it; ii b=*next(it);
				if(a.snd==1&&b.snd==0)pq.push({a.fst-b.fst,a});
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}

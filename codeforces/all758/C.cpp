#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),b(n);
		set<ii> sta,stb;
		fore(i,0,n)cin>>a[i],sta.insert({a[i],i});
		fore(i,0,n)cin>>b[i],stb.insert({b[i],i});
		ll mx=max_element(ALL(a))-a.begin();
		queue<ll> q;
		vv vis(n);
		auto visit=[&](ll x){
			// cerr<<"visit "<<x<<"\n";
			assert(!vis[x]);
			sta.erase({a[x],x});
			stb.erase({b[x],x});
			q.push(x);
			vis[x]=1;
		};
		visit(mx);
		while(SZ(q)){
			ll x=q.front(); q.pop();
			// cerr<<x<<":\n";
			fore(w,0,2){
				auto &st=w?stb:sta;
				// for(auto i:st)cerr<<i.fst<<","<<i.snd<<" ";;cerr<<"\n";
				auto val=w?b[x]:a[x];
				for(auto it=st.lower_bound({val,-1});it!=st.end();){
					ll y=it->snd;
					it++;
					visit(y);
				}
			}
		}
		fore(i,0,n)cout<<vis[i];;cout<<"\n";
	}
	return 0;
}

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
		vv a(n);
		fore(i,0,n)cin>>a[i];
		set<ll> st; // ids
		set<ii> mns;
		fore(i,0,n)st.insert(i),mns.insert({a[i],i});
		ll res=0;
		while(SZ(st)){
			res++;
			if(SZ(st)>=2){
				auto i=*st.begin();
				auto j=*next(st.begin());
				if(a[i]==a[j]){
					st.erase(i); mns.erase({a[i],i});
					st.erase(j); mns.erase({a[j],j});
					continue;
				}
			}
			auto [asd,i]=*mns.begin();
			st.erase(i); mns.erase({a[i],i});
		}
		cout<<res<<"\n";
	}
	return 0;
}
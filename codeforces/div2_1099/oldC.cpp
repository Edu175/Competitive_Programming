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
typedef tuple<ll,ll,ll> tri;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		multiset<ll> st;
		priority_queue<tri> pq;
		auto agr=[&](ll i){
			ll v=a[i];
			st.insert(v);
			pq.push({v%2,__lg(v),i});
		};
		auto done=[&](){
			return *st.begin()==*st.rbegin();
		};
		fore(i,0,n){
			cin>>a[i];
			agr(i);
		}
		ll res=0;
		while(!done()){
			auto [asd,asdd,i]=pq.top(); pq.pop();
			// show(a)
			// cout<<i<<"\n\n";
			st.erase(st.find(a[i]));
			if(a[i]&1)a[i]++;
			else a[i]>>=1;
			agr(i);
			res++;
		}
		cout<<res<<"\n";
	}
	return 0;
}

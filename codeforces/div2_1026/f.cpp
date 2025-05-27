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

struct pinga{
	ll x,ty,w;
	bool operator<(const pinga& b)const{
		return ii({x,ty})<ii({b.x,b.ty});
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		set<pinga>st;
		ll res=0;
		auto cand=[&](ll x, ll y){
			res=max(res,x%y+y%x);
		};
		auto put=[&](pinga a){
			auto it=st.lower_bound(a);
			if(a.ty){ // element
				
			}
		};
		
		auto add=[&](ll x){
			if(st.count(x))return;
			st.insert(x);
			for(ll y=2*x;1;y+=x){
				auto it=st.lower_bound(y);
				// cout<<x<<" "<<y<<": prev "<<*it<<endl;
				cand(x,*prev(it));
				if(it==st.end())break;
			}
			ll y=x;
			while(1){
				ll c=y/x;
				auto it=st.upper_bound(y/(c+1));
				cand(*it,y);
				if(it==st.begin())break;
				x=*prev(it);
			}
		};
		fore(i,0,n){
			add(a[i]);
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

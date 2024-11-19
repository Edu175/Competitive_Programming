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
	ll n,q; cin>>n>>q;
	vv oc(n+5),col(n);
	set<ii>st;
	fore(i,0,n)st.insert({i,i+1}),oc[i]++,col[i]=i;
	auto paint=[&](ll p, ll c){
		// cout<<"\npaint "<<p<<" "<<c<<":\n";
		// impr(st);
		auto it=st.upper_bound({p,n+5}); it--;
		auto [l,r]=*it;
		// cout<<l<<","<<r<<"\n";
		oc[col[l]]-=r-l;
		oc[c]+=r-l;
		while(next(it)!=st.end()&&col[next(it)->fst]==c)
			r=next(it)->snd,st.erase(next(it));
		while(it!=st.begin()&&col[prev(it)->fst]==c)
			l=prev(it)->fst,st.erase(prev(it));
		col[l]=c;
		st.erase(*it);
		st.insert({l,r});
	};
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll x,c; cin>>x>>c; x--; c--;
			paint(x,c);
		}
		else {
			ll c; cin>>c; c--;
			cout<<oc[c]<<"\n";
		}
	}
	return 0;
}

#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k

int main(){
    JET
    ll n,m; cin>>n>>m;
    vector<pair<ii,ii>> a(n);
	vector<ii>ps(m);
	fore(i,0,n){
		cin>>a[i].fst.fst>>a[i].fst.snd;
		cin>>a[i].snd.fst>>a[i].snd.snd;
	}
	fore(i,0,m)cin>>ps[i].fst>>ps[i].snd;
	vector<pair<ll,ii>>ev;
	fore(i,0,n){
		ev.pb({a[i].fst.fst,{1,i}});
		ev.pb({a[i].snd.fst,{2,i}});
	}
	fore(i,0,m){
		ev.pb({ps[i].fst,{0,i}});
	}
	sort(ALL(ev));
	ordered_set st;
	ll cnt=0;
	vector<ll>ans(n);
	for(auto [t,par]:ev){
		auto [ty,i]=par;
		if(ty==0)st.insert({ps[i].snd,cnt++});
		else {
			ll l=a[i].fst.snd;
			ll r=a[i].snd.snd;
			ll q=st.order_of_key({r,-1})-
				 st.order_of_key({l,-1});
			ans[i]+=(ty==1?-1:1)*q;
		}
	}
	// imp(ans)
	ll res=0;
	fore(i,0,n)res+=(m-ans[i])*ans[i]*2;
	ld out=res/ld(m*m);
	cout<<fixed<<setprecision(15)<<out<<"\n";
    return 0;
}
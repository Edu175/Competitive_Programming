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
		ll n,k,q; cin>>n>>k>>q;
		set<ll> nmn,nmx;
		fore(i,0,n)nmn.insert(i);
		fore(i,0,n)nmx.insert(i);
		fore(_,0,q){
			ll c,l,r; cin>>c>>l>>r; l--;
			auto &st=c==1?nmn:nmx;
			for(auto it=st.lower_bound(l);it!=st.end()&&*it<r;){
				it=st.erase(it);
			}
		}
		// imp(st) cout<<"st\n";
		fore(i,0,n){
			ll x=k+1;
			if(!nmn.count(i)&&!nmx.count(i))x=k+1;
			else if(!nmn.count(i))x=k;
			else x=i%k;
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

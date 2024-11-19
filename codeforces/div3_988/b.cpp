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
		ll k; cin>>k;
		set<ll>st;
		ll res=-1;
		fore(i,0,k){
			ll x; cin>>x; st.insert(x);
		}
		k-=2;
		for(auto i:st){
			if(k%i==0&&st.count(k/i))res=i;
		}
		cout<<res<<" "<<k/res<<"\n";
	}
	return 0;
}

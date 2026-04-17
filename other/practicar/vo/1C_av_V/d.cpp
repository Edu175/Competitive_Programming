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
	ll n; cin>>n;
	vv a(n);
	set<ll>st;
	fore(i,0,n){
		cin>>a[i];
		st.insert(a[i]);
	}
	while(1){
		auto x=*st.rbegin();
		ll y=x;
		while(y>=1&&st.count(y))y/=2;
		if(!y){
			// cout<<x<<"\n";
			break;
		}
		st.erase(x);
		st.insert(y);
	}
	for(auto i:st)cout<<i<<" ";;cout<<"\n";
	return 0;
}

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
		ll n,k; cin>>n>>k;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		if(k==1){
			ll sum=accumulate(ALL(a),0ll);
			set<ll> st(ALL(b));
			ll mex=0;
			while(st.count(mex))mex++;
			cout<<mex*sum<<"\n";
			continue;
		}
		ll sum=0;
		fore(i,0,n)if(!b[i])sum+=a[i];
		cout<<sum<<"\n";
	}
	return 0;
}

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
typedef ll node;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv is(n);
		for(ll i=n-1-k;i>=0;i-=k+1)is[i]=1;
		// imp(is)
		multiset<ll>st;
		ll res=0;
		fore(i,0,n){
			st.insert(a[i]);
			if(is[i])res+=*st.rbegin(),st.erase(prev(st.end()));
		}
		cout<<res<<"\n";
	}
	return 0;
}

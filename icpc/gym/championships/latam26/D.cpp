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
	ll n,x,k; cin>>n>>x>>k; x++;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	multiset<ll> st;
	fore(i,n-k,n)st.insert(a[i]);
	ll res=0;
	for(ll i=n-1;i>=0;i--){
		ll col=(i+1)%x==0;
		if(i-k>=0)st.insert(a[i-k]);
		ll v=col?*st.rbegin():*st.begin();
		st.erase(st.find(v));
		res+=col*v/2;
	}
	cout<<res<<"\n";
	return 0;
}
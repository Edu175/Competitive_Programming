#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,x; cin>>n>>x;
	vector<ll>a(n);
	multiset<ll>st;
	fore(i,0,n)cin>>a[i],st.insert(a[i]);
	ll res=0;
	while(SZ(st)){
		auto v=*prev(st.end());
		st.erase(prev(st.end()));
		auto p=st.upper_bound(x-v);
		if(p!=st.begin())st.erase(--p);
		res++;
	}
	cout<<res<<"\n";
	return 0;
}

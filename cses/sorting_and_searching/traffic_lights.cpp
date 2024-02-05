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
	ll n,k; cin>>k>>n;
	set<ll>st={0,k};
	multiset<ll>can={k};
	fore(i,0,n){
		ll x; cin>>x;
		auto p=st.lower_bound(x);
		ll r=*p,l=*(--p);
		//imp(st);
		//cout<<x<<": "<<l<<" "<<r<<endl;
		can.erase(can.find(r-l));
		can.insert(x-l);
		can.insert(r-x);
		st.insert(x);
		cout<<*prev(can.end())<<" ";
		//cout<<endl;
	}
	cout<<"\n";
	return 0;
}

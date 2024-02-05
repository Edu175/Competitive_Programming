#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	multiset<ll> ls,rs;
	fore(i,0,n)rs.insert(a[i]+i);
	ll res=0;
	fore(i,0,n){
		ls.insert(i-a[i]);
		ll l=*prev(ls.end());
		ll r=*rs.begin();
		res=max(res,min({(r-l)/2+1,(ll)SZ(ls),(ll)SZ(rs)}));
		rs.erase(rs.lower_bound(i+a[i]));
	}
	//res=min(res,(n+1)/2);
	cout<<res<<"\n";
	return 0;
}

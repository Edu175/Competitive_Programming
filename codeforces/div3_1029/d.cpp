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
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		set<ll>st;
		fore(i,0,n-1){
			st.insert(a[i+1]-a[i]);
		}
		if(SZ(st)>1)cout<<"NO\n";
		else {
			ll d=*st.begin();
			ll mn=*min_element(ALL(a));
			d=abs(d);
			mn-=d;
			if(mn>=0&&mn%(n+1)==0)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}

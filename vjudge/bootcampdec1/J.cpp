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
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll>a(n);
		set<ll>st;
		fore(i,0,n)cin>>a[i],st.insert(a[i]);
		ll flag=0;
		fore(i,0,n)if(st.count(a[i]+k))flag=1;
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

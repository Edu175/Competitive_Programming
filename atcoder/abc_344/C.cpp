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
	vector<ll>a[3];
	fore(h,0,3){
		ll n; cin>>n;
		a[h].resize(n);
		fore(i,0,n)cin>>a[h][i];
	}
	set<ll>st;
	fore(i,0,SZ(a[0]))fore(j,0,SZ(a[1]))fore(k,0,SZ(a[2])){
		st.insert(a[0][i]+a[1][j]+a[2][k]);
	}
	ll q; cin>>q;
	while(q--){
		ll x; cin>>x;
		if(st.count(x))cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}

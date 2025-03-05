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

multiset<ll>st;

bool f(ll n){
	if(!SZ(st)||n<*st.begin())return 0;
	if(st.count(n)){
		st.erase(st.find(n));
		return 1;
	}
	return f(n/2)&&f((n+1)/2);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv a(n),b(m);
		st.clear();
		fore(i,0,n)cin>>a[i],st.insert(a[i]);
		fore(i,0,m)cin>>b[i];
		ll res=1;
		for(auto i:b)res&=f(i);
		res&=!SZ(st);
		if(res)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}

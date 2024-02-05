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

bool can(ll a, ll b){
	if(b<(a+1)/2)return 1;
	return 0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),b;
		fore(i,0,n)cin>>a[i];
		ll flag=1;
		set<ll>st;
		fore(i,0,n)st.insert(i+1);
		fore(i,0,n){
			if(st.count(a[i]))st.erase(a[i]);
			else b.pb(a[i]);
		}
		sort(ALL(b));
		vector<ll>c;
		for(auto i:st)c.pb(i);
		fore(i,0,SZ(b))if(!can(b[i],c[i]))flag=0;
		if(!flag)cout<<"-1\n";
		else cout<<SZ(b)<<"\n";
	}
	return 0;
}

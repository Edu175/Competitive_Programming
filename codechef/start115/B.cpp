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
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		set<ii>st;
		vector<ll>b;
		ll sum=0;
		fore(i,0,n){
			if(!SZ(st)||st.lower_bound(ii({a[i],-1}))==st.begin())b.pb(a[i]);
			else sum++;
			st.insert({a[i],i});
		}
		ll res=n;
		fore(i,0,SZ(b)){
			res=min(res,sum+i+b[i]);
		}
		cout<<res<<"\n";
	}
	return 0;
}

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
		sort(ALL(a));
		vv b={a[0]},out;
		ll g=a[0];
		a.erase(a.begin());
		ll res=g;
		while(SZ(a)){
			set<ll>st;
			vv ai;
			for(auto &i:a){
				i=gcd(g,i);
				if(!st.count(i)){
					st.insert(i);
					ai.pb(i);
				}
				else out.pb(i);
			}
			swap(a,ai);
			sort(ALL(a));
			g=gcd(g,a[0]);
			a.erase(a.begin());
			res+=g;
		}
		res+=g*SZ(out);
		cout<<res<<"\n";
	}
	return 0;
}

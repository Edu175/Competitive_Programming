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
		vv c(3);
		vv a(n);
		fore(i,0,n)cin>>a[i],c[a[i]]++;
		vv b;
		fore(i,0,3)fore(j,0,c[i])b.pb(i);
		ll s=-1;
		fore(i,0,n)if(b[i]==1)s=i;
		set<ii>st;
		fore(i,0,n)if(i!=s){
			st.insert({a[i]-b[i],i});
		}
		vector<ii>res;
		auto sw=[&](ll i, ll j){
			st.erase({a[i]-b[i],i});
			st.erase({a[j]-b[j],j});
			
		};
	}
	return 0;
}

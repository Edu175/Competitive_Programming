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
		vector<vv> a(n);
		set<ll> vis;
		fore(i,0,n){
			ll m; cin>>m;
			set<ll> st;
			vv v(m);
			fore(j,0,m)cin>>v[j];
			reverse(ALL(v));
			for(auto x:v){
				if(!st.count(x))a[i].pb(x);
				st.insert(x);
			}
		}
		vv res;
		fore(_,0,n){
			vv mn;
			fore(i,0,n){
				vv b;
				fore(j,0,SZ(a[i]))if(!vis.count(a[i][j]))b.pb(a[i][j]);
				a[i]=b;
				if(!SZ(a[i]))continue;
				if(!SZ(mn)||(a[i]<mn))mn=a[i];
			}
			if(!SZ(mn))break;
			for(auto i:mn)vis.insert(i),res.pb(i);
		}
		imp(res)
	}
	return 0;
}

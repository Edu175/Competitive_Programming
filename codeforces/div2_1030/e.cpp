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
		ll n,m; cin>>n>>m;
		vector<ii>ret;
		ll h=n/2,w=m/2;
		vv alt;
		fore(i,0,max(n,m)+5){
			alt.pb(-i);
			if(i)alt.pb(i);
		}
		set<ii>st;
		auto pone=[&](ll i, ll j){
			// cout<<"pone "<<i+1<<" "<<j+1<<endl;
			if(i>=0&&i<n&&j>=0&&j<m){
				assert(!st.count({i,j}));
				st.insert({i,j});
				ret.pb({i,j});
			}
		};
		pone(h,w);
		fore(i,1,max(n,m)+5){
			ll u=h-i,d=h+i;
			ll l=w-i,r=w+i;
			// cout<<i<<" i:\n";
			// caso general:
			for(auto j:alt){
				// cout<<j<<" j:\n";
				if(w+j==r)break; // corta en la esquina
				pone(u,w+j);
				pone(h+j,r);
				pone(d,w-j);
				pone(h-j,l);
			}
		}
		assert(SZ(ret)==n*m);
		for(auto [i,j]:ret){
			cout<<i+1<<" "<<j+1<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}

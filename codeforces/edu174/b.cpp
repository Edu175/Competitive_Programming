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
		vector<vv> a(n,vv(m));
		set<ii> st[n*m];
		fore(i,0,n)fore(j,0,m){
			cin>>a[i][j];
			a[i][j]--;
			st[a[i][j]].insert({i,j});
		}
		ll hay=0;
		ll res=0;
		fore(c,0,n*m)if(SZ(st[c])){
			auto &s=st[c];
			ll is=1;
			for(auto [i,j]:s){
				is&=!s.count({i-1,j});
				is&=!s.count({i,j-1});
			}
			res+=is?1:2;
			hay|=!is;
		}
		cout<<res-hay-1<<"\n";
	}
	return 0;
}

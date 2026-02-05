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
		vector<vv> a(2,vv(n));
		vector<vector<ii>> pos(2*n);
		fore(i,0,2)fore(j,0,n){
			cin>>a[i][j];
			a[i][j]--;
			pos[a[i][j]].pb({i,j});
		}
		vector<set<ll>> sts(2);
		fore(w,0,2)fore(i,0,n)sts[w].insert(i);
		sts[0].insert(n);
		sts[1].insert(-1);
		auto agr=[&](ll v){
			for(auto [i,j]:pos[v]){
				sts[i].erase(j);
			}
		};
		auto sac=[&](ll v){
			for(auto [i,j]:pos[v]){
				sts[i].insert(j);
			}
		};
		auto good=[&](){
			ll l=*sts[0].begin();
			ll r=*sts[1].rbegin();
			return l>=r+2;
		};
		ll r=0,res=0;
		fore(l,0,2*n){
			while(r<2*n&&!good())agr(r++);
			if(good())res+=2*n-r+1;
			// cout<<l<<","<<r<<"\n";
			sac(l);
		}
		cout<<res<<"\n";
	}
	return 0;
}

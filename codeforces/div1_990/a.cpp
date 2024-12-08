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
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst;
		fore(i,0,n)cin>>a[i].snd;
		auto solve=[&](vector<ii>a){
			ll n=SZ(a);
			ll res=0;
			for(auto [x,y]:a)res+=max(x,y);
			return res;
		};
		ll res=-1e12;
		fore(i,0,n){
			auto ai=a;
			ai.erase(ai.begin()+i);
			res=max(res,solve(ai)+a[i].fst+a[i].snd);
		}
		cout<<res<<"\n";
	}
	return 0;
}
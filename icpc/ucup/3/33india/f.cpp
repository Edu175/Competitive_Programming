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
const ll MAXK=35,INF=2e9;

ll cut(ll x){return min(x,INF);}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vector<ii>_a(n);
		fore(i,0,n)cin>>_a[i].fst;
		fore(i,0,n)cin>>_a[i].snd;
		vector<ii>a;
		ll fij=0; vv m0;
		fore(i,0,n){
			if(!_a[i].snd)fij++;
			else if(!_a[i].fst)m0.pb(_a[i].snd);
			else a.pb(_a[i]);
		}
		sort(ALL(m0)); vv sp(SZ(m0)+1);
		fore(i,1,SZ(sp))sp[i]=sp[i-1]+m0[i-1];
		auto resto=[&](ll h){
			return upper_bound(ALL(sp),h)-sp.begin()-1;
		};
		sort(ALL(a),[&](ii a, ii b){
			return a.snd*b.fst<b.snd*a.fst;
		});
		reverse(ALL(a));
		n=SZ(a);
		vector<vv> dp(n+1,vv(MAXK));
		fore(k,1,MAXK)dp[n][k]=INF;
		for(ll i=n-1;i>=0;i--)fore(k,0,MAXK){
			auto &res=dp[i][k];
			res=dp[i+1][k];
			if(k){
				ll x=dp[i+1][k-1];
				ll go1=cut(x+a[i].fst*x+a[i].snd);
				res=min(res,go1);
			}
		}
		while(q--){
			ll p; cin>>p;
			ll res=0;
			fore(k,0,MAXK){
				ll pi=dp[0][k];
				if(p>=pi)res=max(res,k+resto(p-pi));
			}
			cout<<res+fij<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

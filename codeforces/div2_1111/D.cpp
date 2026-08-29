#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll N=1; while(N<n)N+=N;
		ll B=__lg(N);
		vector<vv> mns(B),mxs(B);
		fore(j,0,B){
			ll z=N>>j;
			mns[j]=vv(z,INF);
			mxs[j]=vv(z,-INF);
		}
		fore(i,0,n){
			fore(j,0,B){
				auto &mn=mns[j];
				auto &mx=mxs[j];
				ll p=i>>j;
				mn[p]=min(mn[p],a[i]);
				mx[p]=max(mx[p],a[i]);
			}
		}
		vv bad(B);
		fore(j,0,B)fore(i,0,SZ(mns[j])-1){
			if(mxs[j][i]>mns[j][i+1])bad[j]++;
		}
		auto query=[&](){
			// cerr<<"query\n";
			// show(a)
			// fore(j,0,B){
			// 	fore(i,0,SZ(mns[j]))cerr<<mns[j][i]<<","<<mxs[j][i]<<" ";
			// 	cerr<<"\n";
			// }
			// cerr<<"bad: ";show(bad)
			ll res=0;
			fore(i,0,B)if(bad[i])res=1ll<<i;
			cout<<res<<"\n";
		};
		auto upd=[&](ll j, ll p, ll fg){
			auto &mn=mns[j];
			auto &mx=mxs[j];
			if(!p||p==SZ(mn))return;
			if(mx[p-1]>mn[p])bad[j]+=fg;
		};
		query();
		while(q--){
			ll i,v; cin>>i>>v;
			a[i]=v;
			fore(j,0,B){
				ll p=i>>j;
				upd(j,p,-1); upd(j,p+1,-1);
				if(j){
					mns[j][p]=min(mns[j-1][2*p],mns[j-1][2*p+1]);
					mxs[j][p]=max(mxs[j-1][2*p],mxs[j-1][2*p+1]);
				}
				else mxs[j][i]=mns[j][i]=v;
				upd(j,p,+1); upd(j,p+1,+1);
			}
			query();
		}
	}
	return 0;
}

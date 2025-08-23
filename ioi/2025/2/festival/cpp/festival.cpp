#include "festival.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e15;

vector<int> max_coupons(int A, vector<int> P, vector<int> T) {
	ll n=SZ(P);
	vector<vv> h(5);
	vv p(n); fore(i,0,n)p[i]=P[i];
	fore(i,0,n)h[T[i]].pb(i);
	fore(t,1,5)sort(ALL(h[t]),[&](ll i, ll j){return p[i]<p[j];});
	vv zs(5); fore(i,1,5)zs[i]=SZ(h[i]);
	vv sp(zs[1]+1);
	fore(i,0,zs[1])sp[i+1]=sp[i]+p[h[1][i]];
	auto ones=[&](ll v)->ll{
		return upper_bound(ALL(sp),v)-sp.begin()-1;
	};
	
	vector<vector<vector<ll>>> dp(zs[4]+1,
		vector<vector<ll>>(zs[3]+1,vector<ll>(zs[2]+1,-1)));
	auto fr=dp;
	dp[0][0][0]=A;
	array<ll,3> ans={-1,-1,-1}; ll mx=0;
	auto go=[&](ll v, ll i){return (v-p[i])*T[i];};
	
	auto maxig=[&](ll i, ll j, ll k, ll t, ll v){
		auto &to=dp[i][j][k];
		if(v>to){
			fr[i][j][k]=t;
			to=v;
		}
	};
		
	fore(i,0,zs[4]+1)fore(j,0,zs[3]+1)fore(k,0,zs[2]+1){
		auto &v=dp[i][j][k];
		v=min(v,INF);
		if(v<0)continue;
		ll vt=i+j+k+ones(v);
		if(vt>mx)ans={i,j,k},mx=vt;
		auto gow=[&](ll t){
			ll ind=vv({i,j,k})[4-t];
			if(ind<zs[t]){
				ll vi=go(v,h[t][ind]);
				maxig(i+(t==4),j+(t==3),k+(t==2),t,vi);
			}
		};
		gow(4);
		gow(3);
		gow(2);
	}
	// cerr<<mx<<"\n";
	auto [i,j,k]=ans;
	if(i==-1)return {};
	// assert(i!=-1);
	ll v=dp[i][j][k];
	vector<int> res;
	fore(i,0,zs[1]){
		ll ind=h[1][i];
		v-=p[ind];
		if(v>=0)res.pb(ind);
	}
	while(1){
		ll t=fr[i][j][k];
		if(t==-1)break;
		if(t==4)i--;
		if(t==3)j--;
		if(t==2)k--;
		ll ind=vv({i,j,k})[4-t];
		res.pb(h[t][ind]);
	}
	reverse(ALL(res));
	return res;
}

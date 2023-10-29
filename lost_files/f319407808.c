#include "towers.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto sjkg:v)cout<<sjkg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define NEUT 0
#define oper max
struct STree{
	vector<ll>t; ll n;
	STree(){}
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
const ll MAXN=1e5+5;
ll n,h[MAXN];
ll pos[MAXN][2];
vector<ii>vp[2];
ll lwb(ll x, ll b){
	// first >=x or first <=x
	ll l=0,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(b){
			if(vp[b][m].fst>=x)r=m-1;
			else l=m+1;
		}
		else {
			if(vp[b][m].fst<=x)r=m-1;
			else l=m+1;
		}
	}
	return l;
}
/*ll lwb(ii x, ll b){
	ll ret;
	if(b){
		ret=lower_bound(ALL(vp[b]),x)-vp[b].begin();
	}
	else {
		x.fst*=-1;
		ret=upper_bound(ALL(vp[b]),-x)-vp[b].begin()-1;
		ret=SZ(vp[b])-1-ret;
	}
	return ret;
}*/

void init(int N, std::vector<int> H){
	n=N;
	fore(i,0,n)h[i]=H[i];
	fore(b,0,2){
		fore(i,0,n){
			vp[b].pb({h[i],i});
		}
		sort(ALL(vp[b]));
		if(!b)reverse(ALL(vp[b]));
		fore(i,0,n)pos[vp[b][i].snd][b]=i;
		//imp(vp[b]);
	}
}

int max_towers(int L, int R, int D){
	ll l=L,r=R+1,d=D;
	vector<STree> st(2,STree(n));
	vector<vector<ll>> dp(n+3,vector<ll>(2));
	ll ans=0;
	for(ll i=r-1;i>=l;i--){
		fore(b,0,2){//query
			ll &res=dp[i][b];
			ll x=h[i]+d;
			if(b)x=h[i]-d;
			//ll idx=lwb(x,b^1);
			res=st[b^1].query(lwb(x,b^1),n)+(!b);
			ans=max(res,ans);
			//cout<<i<<" "<<b<<":\n";
			//cout<<"query ["<<lwb(x,b^1)<<": "<<res-(!b)<<": "<<res<<"\n";
		}
		fore(b,0,2){//upd
			ll &res=dp[i][b];
			st[b].upd(pos[i][b],res);
			//cout<<"upd "<<pos[i][b]<<": "<<res<<"\n";
		}
	}
	/*fore(b,0,2){
		fore(i,0,n)cout<<dp[i][b]<<" ";
		cout<<"\n";
	}*/
	//return dp[l][0];
	//return max(dp[l][0],dp[l][1]);
	return ans;
}

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

vv get_divs(ll n){
	vv ret;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0)ret.pb(i),ret.pb(n/i);
		if(i*i==n)ret.pop_back();
	}
	sort(ALL(ret));
	return ret;
}
vector<vv> ds;
vector<vector<vv>> divs;
ll get_idx(ll w, ll d){
	auto &v=ds[w];
	ll p=lower_bound(ALL(v),d)-v.begin();
	assert(p<SZ(v)&&v[p]==d);
	return p;
}
vector<vv> dp;
vector<vv> sums;
ll f(ll i, ll j){
	auto &res=dp[i][j];
	if(res!=-1)return res;
	if(i==0&&j==0)return res=0;
	res=sums[0][i]+sums[1][j]; // bound
	fore(w,0,2){
		ll me=i,he=j; if(w)swap(me,he);
		auto &otr=divs[w^1][he];
		ll po=0;
		for(auto d1:divs[w][me])if(d1>1){
			if(d1>res)break;
			while(po<SZ(otr)&&otr[po]<=d1)po++;
			if(po){
				ll d2=otr[po-1];
				ll pi=get_idx(w,ds[w][me]/d1);
				ll pj=get_idx(w^1,ds[w^1][he]/d2);
				ll cur=!w?f(pi,pj):f(pj,pi);
				cur+=d1;
				res=min(res,cur);
			}
		}
	}
	return res;
}
int main(){FIN;
	ll a,b; cin>>a>>a>>b;
	ll g=gcd(a,b);
	a/=g,b/=g;
	ds.pb(get_divs(a));
	ds.pb(get_divs(b));
	fore(w,0,2){
		auto v=ds[w];
		divs.pb(vector<vv>(SZ(v)));
		fore(i,0,SZ(v))fore(j,i,SZ(v)){
			if(v[j]%v[i]==0)divs[w][j].pb(v[i]);
		}
		sums.pb(vv(SZ(v)));
		fore(i,1,SZ(v)){
			ll p=divs[w][i][1];
			ll j=get_idx(w,v[i]/p);
			sums[w][i]=sums[w][j]+p;
		}
	}
	dp=vector<vv>(SZ(ds[0]),vv(SZ(ds[1]),-1));
	// cerr<<SZ(ds[0])<<" "<<SZ(ds[1])<<"\n";
	cout<<f(SZ(ds[0])-1,SZ(ds[1])-1)<<"\n";
	return 0;
}

#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll LG=20,MAXN=1<<LG;

int main(){
    JET
	ll n; cin>>n;
	vv a(n);
	ll all=0;
	fore(i,0,n)cin>>a[i],all^=a[i];
	ll x=0;
	vv b;
	for(auto v:a){
		x^=v;
		ll r=all^x;
		ll cur=x|r;
		b.pb(cur);
	}
	b.pop_back();
	vv oc(MAXN);
	for(auto i:b)oc[i]++;
	auto dp=oc;
	fore(j,0,LG)fore(mk,0,MAXN){
		if(mk>>j&1)dp[mk]+=dp[mk^(1ll<<j)];
	}
	// cerr<<*max_element(ALL(dp))<<" max element\n";
	vv ans(n); // # of cuts
	ll po=0;
	fore(k,0,n){
		while(dp[po]<k)po++;
		ans[k]=po;
	}
	ans[0]=all;
	for(auto i:ans)cout<<i<<" ";;cout<<"\n";
    return 0;
}
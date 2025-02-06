#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC optimize("avx2,bmi,bmi2,popcnt,lzcnt")
ll B=60;
const ll MAXN=205,INF=61*1e15;
ll a[MAXN],n;
unordered_map<ll,ll>mp;

ll clz(ll n){return __builtin_clzll(n);}
ll ctz(ll n){return __builtin_ctzll(n);}
ll ppc(ll n){return __builtin_popcountll(n);}
ll f(ll m, ll i){
	if(i==-1)return 0;
	if(m<0)return -INF;
	// if(mp.count(m)&&mp[m]<i)return 0;
	mp[m]=i;
	ll res=-INF;
	vv cand;
	fore(k,0,64-clz(m)){
		ll num=-1,cnt=0,acum=0;
		for(ll j=B-1;j>=0;j--)if(m>>j&1){
			ll c=k-cnt,ones=(1ll<<c)-1;
			if(j-c<0)break;
			ll n=acum|(ones<<(j-c));
			num=max(num,n);
			acum|=1ll<<j; cnt++;
		}
		if(num==-1)break;
		cand.pb(num);
	}
	// cout<<m<<": ";
	// for(auto i:cand)cout<<i<<" ";;cout<<"\n";
	sort(ALL(cand)); reverse(ALL(cand));
	for(auto n:cand){
		assert(n<m);
		res=max(res,a[i]*__builtin_popcountll(n)+f(n,i-1));
	}
	return res;
}

int main(){
	JET
	ll m; cin>>n>>m; m++;
	fore(i,0,n)cin>>a[i];
	cout<<f(m,n-1)<<"\n";
	return 0;
}
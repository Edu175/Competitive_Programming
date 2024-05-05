#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,rus=b;i<rus;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto sdkjg:v)cout<<sdkjg<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef short ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=2005;
unordered_map<ll,ll> dp[MAXN][MAXN];

ll a[MAXN];

inline static ll f(ll l, ll r, ll v){
	if(l>r)return v;
	if(dp[l][r].count(v))return dp[l][r][v];
	ll &res=dp[l][r][v];
	ll gol=f(l+1,r,v<=0?v+a[l]:v-a[l]);
	ll gor=f(l,r-1,v<=0?v+a[r]:v-a[r]);
	//cout<<l<<" "<<r<<" "<<v<<": "<<gol<<" "<<gor<<"\n";
	if(v<=0)return res=max(gol,gor);
	return res=min(gol,gor);
}

int main(){FIN;
	ll n; cin>>n;
	ll sum=0;
	fore(i,0,n)cin>>a[i],sum+=a[i];
	ll res=f(0,n-1,0);
	//cout<<res<<"\n";
	cout<<res+(sum-res)/2<<" "<<(sum-res)/2<<"\n";
	return 0;
}

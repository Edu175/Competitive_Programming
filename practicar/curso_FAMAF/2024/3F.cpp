#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXS=1e6+5,MAXN=105;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll w,f; cin>>w>>f;
		ll n; cin>>n;
		vector<ll>a(n);
		ll sum=0;
		fore(i,0,n)cin>>a[i],sum+=a[i];
		bitset<MAXS> dp;
		auto can=[&](ll t){
			ll wi=w*t,fi=f*t;
			fore(s,0,MAXS)dp[s]=(s<=fi&&sum-s<=wi);
			fore(i,0,n)dp|=dp>>a[i];
			return dp[0];
		};
		ll l=0,r=1e8;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))r=m-1;
			else l=m+1; 
		}
		cout<<l<<"\n";
	}
	return 0;
}

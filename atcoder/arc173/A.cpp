#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define bint __int128
bint dp[25][12][2][2];
string s;
bint f(ll i, ll u, ll b, ll z){
	bint &res=dp[i][u][b][z];
	if(res!=-1)return res;
	if(i==SZ(s))return res=z;
	if(!z)u=10;
	res=0;
	ll e=9;
	if(b)e=s[i]-'0';
	fore(j,0,e+1)if(j!=u)res+=f(i+1,j,b&&(j==e),z||j);
	return res;
}
ll k;
bool can(ll m){
	s=to_string(m);
	mset(dp,-1);
	bint c=f(0,10,1,0);
	// cout<<"f "<<m<<": "<<c<<"\n";
	return c<k;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>k;
		ll l=1,r=1e18;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))l=m+1;
			else r=m-1;
		}
		cout<<l<<"\n";
	}
	return 0;
}

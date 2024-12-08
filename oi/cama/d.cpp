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

vv l,r;
ll dp[40][2][2][2];
ll f(ll i, ll s, ll e, ll has){
	if(i==-1)return has;
	auto &res=dp[i][s][e][has];
	if(res!=-1)return res;
	fore(p,0,2)fore(q,0,2){
		if(!has&&)
	}
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		mset(dp,-1);
		
	}
	return 0;
}

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
const ll MAXN=105,MAXS=505,INF=MAXN*5;

ll sum,n;
ll s[MAXN],t[MAXN];
ll dp[MAXN][MAXS][MAXS];

ll f(ll i, vv a){
	ll &res=dp[i][a[0]][a[1]];
	if(res!=-1)return res;
	if(i==n)return res=a[0]==sum/3&&a[1]==a[0]&&a[2]==a[0]?0:INF;
	res=INF;
	fore(j,0,3){
		vv ai=a;
		ai[j]+=s[i];
		if(ai[j]>sum/3)continue;
		res=min(res,(j!=t[i])+f(i+1,ai));
	}
	return res;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>t[i]>>s[i],sum+=s[i],t[i]--;
	mset(dp,-1);
	if(sum%3)cout<<"-1\n";
	else {
		ll res=f(0,{0,0,0});
		if(res>=INF)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	return 0;
}

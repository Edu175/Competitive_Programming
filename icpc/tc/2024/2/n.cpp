#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll N=18,MAXN=1ll<<18,INF=4e8;

ll g[N][N];
ll dp[MAXN],dp2[MAXN][N][N][2];

ll ear(ll mk, ll x, ll t);
ll f(ll mk);

ll n;
string cv(ll mk){
	string s(n,'0');
	fore(i,0,n)s[i]+=mk>>i&1;
	return s;
}
ll ear(ll mk, ll x, ll t, bool flag){
	ll &res=dp2[mk][x][t][flag];
	if(res!=-1)return res;
	res=INF;
	fore(y,0,n)if(g[x][y]!=-1){
		if(!(mk>>y&1))
			res=min(res,g[x][y]+ear(mk|(1<<y),y,t,x==t));
		if(y==t&&!flag)res=min(res,g[x][y]+f(mk));
	}
	// cout<<"ear "<<cv(mk)<<" "<<x<<" "<<t<<": "<<res<<"\n";
	return res;
}
ll f(ll mk){
	ll &res=dp[mk];
	if(res!=-1)return res;
	if(mk==(1<<n)-1)return res=0;
	res=INF;
	fore(s,0,n)if(mk>>s&1)fore(t,0,n)if(mk>>t&1)
		res=min(res,ear(mk,s,t,0));
	// cout<<"f "<<cv(mk)<<": "<<res<<"\n";
	return res;
}

int main(){JET
	cin>>n;
	fore(i,0,n)fore(j,0,n){
		cin>>g[i][j];
	}
	ll sum=0;
	fore(i,0,n)fore(j,0,i)if(g[i][j]!=-1){
		ll &a=g[i][j];
		ll &b=g[j][i];
		if(a<b)sum+=a,b-=a,a=0;
		else sum+=b,a-=b,b=0;
	}
	// fore(i,0,n){
	// 	fore(j,0,n)cout<<g[i][j]<<" ";
	// 	cout<<"\n";
	// }
	mset(dp,-1);
	mset(dp2,-1);
	// cout<<sum<<" sum\n";
	ll res=f(1);
	if(res>=INF)cout<<"-1\n";
	else cout<<sum+res<<"\n";
}
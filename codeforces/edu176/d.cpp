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
const ll MAXK=60,INF=1e18;

ll dp[MAXK][MAXK][MAXK];
ll f(ll a, ll b, ll k){
	if(max(a,b)>=MAXK)return INF;
	auto &res=dp[a][b][k];
	if(res!=-1)return res;
	if(k==0)return res=!a&&!b?0:INF;
	res=f(a,b,k-1);
	ll go0=(1ll<<k)+(a-k<0?f(0,b+k-a,k-1):f(a-k,b,k-1));
	ll go1=(1ll<<k)+(b-k<0?f(a+k-b,0,k-1):f(a,b-k,k-1));
	return res=min({res,go0,go1});
}
ll dp2[MAXK][MAXK][MAXK];
ll g(ll a, ll b, ll k){
	auto &res=dp2[a][b][k];
	if(res!=-1)return res;
	if(k==0)return res=!a&&!b?0:INF;
	res=g(a,b,k-1);
	ll go0=(1ll<<k)+g(max(a-k,0ll),b,k-1);
	ll go1=(1ll<<k)+g(a,max(b-k,0ll),k-1);
	res=min({res,go0,go1});
	// if(k<5)cout<<a<<" "<<b<<" "<<k<<": "<<res<<"\n";
	// cout<<a<<" "<<b<<" "<<k<<": "<<res<<"\n";
	// cout<<"pingaa\n";
	return res;
}

int main(){FIN;
	mset(dp,-1);
	mset(dp2,-1);
	ll t; cin>>t;
	while(t--){
		ll x,y; cin>>x>>y;
		ll n=!x?0:__lg(x)+1;
		ll m=!y?0:__lg(y)+1;
		ll p=0;
		while(n-p>=0&&m-p>=0&&(x>>(n-p))==(y>>(m-p)))p++;
		p--;
		// cout<<n<<" "<<m<<": "<< p<<"\n";
		// cout<<endl;
		ll res=g(n,m,MAXK-1);
		// cerr<<res<<" cand\n";
		res=min(res,f(n-p,m-p,MAXK-1));
		cout<<res<<"\n";
		// cout<<"\n";
	}
	return 0;
}

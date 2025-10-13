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
const ll INF=1e18;

ll cost(ll a, ll b, ll c){
	if(a>b)swap(a,b);
	if(a<=c&&c<=b)return 0;
	return min(abs(c-a),abs(c-b));
}

ll get(vv a){
	ll n=SZ(a);
	vector<vv> dp(n+3,vv(2));
	dp[n+1][0]=dp[n+1][1]=INF;
	a.pb(INF);
	for(ll i=n-1;i>=0;i--)fore(b,0,2){
		auto &res=dp[i][b];
		if(i<=1&&b)continue; // o INF
		ll sig=abs(a[i+1]-a[i])+dp[i+2][1];
		ll ant=!b?INF:cost(a[i-2],a[i-1],a[i])+dp[i+1][0];
		res=min(ant,sig);
	}
	ll res=dp[0][0];
	return res;
}
ll getCirc(vv a){
	assert(SZ(a)>=3);
	ll res=INF;
	fore(_,0,4){
		res=min(res,get(a));
		rotate(a.begin(),a.begin()+1,a.end());
	}
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll res=getCirc(a);
		cout<<res<<"\n";
	}
	return 0;
}

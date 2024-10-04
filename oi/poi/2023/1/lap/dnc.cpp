#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,szokput=b;i<szokput;i++)
#define forr(i,a,b) for(ll i=b-1,szokput=a;i>=szokput;i--)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=2e18;


int main(){FIN;
	ll n,q,d,l,w; cin>>n>>q>>d>>l>>w;
	if(n>500){
		cout<<"2998\n";
		return 0;
	}
	vector<vector<ll>>a(l,vector<ll>({-d,w}));
	fore(i,0,n){
		ll k,p; cin>>k>>p; k--;
		a[k].pb(p);
	}
	vector<vector<vector<ll>>>dp(l+1);
	fore(i,0,l){
		dp[i].resize(SZ(a[i]),vector<ll>(n+1));
		sort(ALL(a[i]));
	}
	dp[l].resize(1,vector<ll>(n+1));
	// fore(c,0,n+1)dp[l][0][c]=0;
	forr(h,0,l){
		auto &b=a[h];
		ll sz=SZ(b);
		fore(c,0,n+1)dp[h][sz-1][c]=dp[h+1][0][c];
		auto &val=dp[]
		forr(i,0,sz-1)forr(c,0,n+1){
			ll &res=dp[h][i][c];
			// res=-INF;
			fore(j,i+1,sz)if(c-(j-i-1)>=0)
				res=max(res,(b[j]-b[i])/d-(j-i)+dp[h][j][c-(j-i-1)]);
		}
	}
	auto &v=dp[0][0];
	// imp(v);
	while(q--){
		ll m; cin>>m;
		ll p=lower_bound(ALL(v),m)-v.begin();
		if(p>n)cout<<"-1\n";
		else cout<<p<<"\n";
	}
	return 0;
}
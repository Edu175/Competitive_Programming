#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5005;

ll dp[MAXN][MAXN];
vector<ll>c;
ll f(ll i, ll s){
	ll &res=dp[i][s];
	if(res!=-1)return res;
	if(i==SZ(c))return res=0;
	res=1+f(i+1,s+1);
	if(s>=c[i])res=min(res,f(i+1,s-c[i]));
	// cout<<i<<" "<<s<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		ll q=1;
		c.clear();
		fore(i,1,n){
			if(a[i]!=a[i-1])c.pb(q),q=1;
			else q++;
		}
		c.pb(q);
		// imp(c);
		fore(i,0,SZ(c)+1)fore(j,0,SZ(c)+1)dp[i][j]=-1;
		cout<<f(0,0)<<"\n";
	}
	return 0;
}

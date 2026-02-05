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
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m; n+=2;
		string s; cin>>s;
		s="P"+s+"S";
		vv b(n);
		fore(i,1,n-1)cin>>b[i];
		ll res=0;
		// cout<<s<<"\n";
		// imp(b)
		fore(p,0,n-1){
			if(s[p]=='S')break;
			if(p&&abs(b[p-1]-b[p])>m)break;
			if(s[p+1]=='P')continue;
			// cout<<"proba "<<p<<"\n";
			// s[p,p+1] = "PS"
			ll sum=b[p]+b[p+1];
			vector<vv> dp(n+1,vv(2));
			dp[n][0]=dp[n][1]=1;
			string ps="PS";
			for(ll i=n-1;i>=p+2;i--)fore(w,0,2){
				auto &res=dp[i][w];
				char pr=ps[w];
				fore(now,0,2){
					char ac=ps[now];
					if(s[i]!='?'&&ac!=s[i])continue;
					bool valid=1;
					if(pr==ac)valid=abs(b[i-1]-b[i])<=m;
					else if(pr=='P')valid=b[i-1]+b[i]==sum; // PS
					else valid=abs(b[i-1]+b[i]-sum)<=2*m; // SP
					if(valid)res=add(res,dp[i+1][now]);
				}
			}
			ll cur=dp[p+2][1];
			res=add(res,cur);
		}
		cout<<res<<"\n";
	}
	return 0;
}

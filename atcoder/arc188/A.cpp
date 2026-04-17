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
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
#define addig(a,b) a=add((a),(b))
const ll MAXN=51;
ll dp[2][MAXN][MAXN][MAXN][4];

vv tra={3,1,2};
ll to2(ll n){return n*(n-1)/2;}
int main(){FIN;
	ll n,k; string s; cin>>n>>k>>s;
	dp[0][1][0][0][0]=1;
	fore(i,0,n){
		fore(a,0,n+1)fore(b,0,n+1)fore(c,0,n+1)fore(u,0,4){
			ll d=i+1-a-b-c; if(d<0)continue;
			auto &now=dp[i&1][a][b][c][u];
			if(!now)continue;
			fore(p,0,3){
				if(s[i]!='?'&&s[i]!='A'+p)continue;
				ll nu=u^tra[p];
				addig(dp[(i+1)&1][a+(nu==0)][b+(nu==1)][c+(nu==2)][nu],now);
			}
			now=0;
		}
	}
	ll res=0;
	fore(a,0,n+1)fore(b,0,n+1)fore(c,0,n+1)fore(u,0,4){
		ll d=n+1-a-b-c; if(d<0)continue;
		auto &now=dp[n&1][a][b][c][u];
		if(!now)continue;
		ll cant=to2(a)+to2(b)+to2(c)+to2(d);
		// cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<u<<": "<<now<<" "<<cant<<"\n";
		if(cant>=k)addig(res,now);
	}
	cout<<res<<"\n";
	return 0;
}

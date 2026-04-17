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

const ll MAXN=105,MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll dp[MAXN][MAXN][MAXN][4];

string s;
ll n;

ll f(ll i, ll m, ll q, ll t){
	auto &res=dp[i][m][q][t];
	if(res!=-1)return res;
	if(i==n){
		res=0;
		if(t==3&&q==0){
			assert(m>=2);
			res=m-2;
		}
		return res;
	}
	res=f(i+1,m,q,t);
	if(s[i]=='('){
		ll ti=t+(t==1||t==2);
		res=add(res,f(i+1,m+1,q+1,ti));
	}
	else {
		if(q>0){
			ll ti=t+(t==0);
			res=add(res,f(i+1,m+1,q-1,ti));
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		cin>>s;
		fore(i,0,n+2)mset(dp[i],-1);
		cout<<f(0,0,0,0)<<"\n";
	}
	return 0;
}

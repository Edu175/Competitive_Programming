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
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

const ll MAXN=305;

int dp[MAXN][MAXN][MAXN][5];
ll n;
string a;

ll f(ll i, ll x, ll y, ll t){
	if(x<0||y<0)return 0; // ---------- molesto para iterativa
	auto &res=dp[i][x][y][t];
	if(res!=-1)return res;
	if(i==n)return res=(x+y==0);
	if(a[i]!='?')return res=t==a[i]-'a'?0:f(i+1,x,y,a[i]-'a');
	res=0;
	fore(ty,0,3){
		if(t!=ty)res=add(res,f(i+1,x-(ty==0),y-(ty==1),ty));
	}
	return res;
}

ll sp[MAXN][MAXN];

int main(){FIN;
	mset(dp,-1);
	ll q; cin>>n>>q;
	cin>>a;
	fore(x,0,n+3)fore(y,1,n+4){
		sp[x][y]=add(sp[x][y-1],f(0,x,y-1,3));
	}
	ll s=0;
	for(auto i:a)s+=i=='?';
	while(q--){
		ll X,Y,Z; cin>>X>>Y>>Z;
		ll res=0;
		fore(x,0,X+1){
			ll l=s-x-Z,r=Y+1;
			l=max(l,0ll);
			if(r-l>=0)res=add(res,sub(sp[x][r],sp[x][l]));
		}
		cout<<res<<"\n";
	}
	return 0;
}

#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN=2e6+5,INF=2e9+5;
vector<ll> c(3);
ll a[MAXN],ans[MAXN];
ll dp[4][MAXN];
bool vis[4][MAXN];
ll n;

ll f(ll x, ll i){
	ll &res=dp[x][i];
	if(vis[x][i])return res;
	vis[x][i]=1;
	if(i==n)return res=0;
	if(a[i]!=3){
		if(x==a[i])return res=INF;
		else return res=f(a[i],i+1);
	}
	res=INF;
	fore(j,0,3)if(j!=x)res=min(res,c[j]+f(j,i+1));
	return res;
}
vector<ll> ab;
void build(ll x, ll i, ll ans){
	if(i==n)return;
	if(a[i]==3){
		fore(j,0,3)if(j!=x&&dp[j][i+1]==ans-c[j]){
			ab.pb(j),build(j,i+1,ans-c[j]);
			break;
		}
	}
	else ab.pb(a[i]),build(a[i],i+1,ans);
}


int sendero(int B, int G, int N, string &baldosas){
	string &b=baldosas;
    c={B,G,N};
    n=SZ(b);
    fore(i,0,n){
    	if(b[i]=='B')a[i]=0;
    	else if(b[i]=='G')a[i]=1;
    	else if(b[i]=='N')a[i]=2;
    	else a[i]=3;
    }
    ll res=f(3,0);
    build(3,0,res);
    fore(i,0,n){
    	if(ab[i]==0)b[i]='B';
    	if(ab[i]==1)b[i]='G';
    	if(ab[i]==2)b[i]='N';
    }
    return res;
}

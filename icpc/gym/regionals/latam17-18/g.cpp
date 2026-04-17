#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=4e5+5,MOD=1e9+7;

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		b=mul(b,b);e>>=1;
	}
	return res;
}
ll L[MAXN],R[MAXN],c[MAXN],bad[MAXN];

void dfs(ll x){
	if(L[x]!=-1){
		dfs(L[x]);
		dfs(R[x]);
		c[x]=c[L[x]]+c[R[x]];
	}
}
ll dp[MAXN][2][2];
ll nand(ll i, ll j){return !(i&&j);}
ll f(ll x, ll p, ll q){
	ll &res=dp[x][p][q];
	if(res!=-1)return res;
	if(L[x]==-1)return res=p==q;
	res=0;
	auto fun=[&](ll i, ll j){
		if(bad[x]==-1)return nand(i,j);
		return bad[x];
	};
	fore(i,0,2)fore(j,0,2)fore(k,0,2)fore(l,0,2){
		if(nand(i,j)==p&&fun(k,l)==q){
			res=add(res,mul(f(L[x],i,k),f(R[x],j,l)));
		}
	}
	return res;
}

int main(){ET;
	ll n; cin>>n;
	ll cnt=n;
	fore(i,0,n){
		ll l,r,b; cin>>l>>r>>b; l--,r--;
		if(l==-1)l=cnt++;
		if(r==-1)r=cnt++;
		L[i]=l,R[i]=r,bad[i]=b;
	}
	fore(i,n,cnt){
		bad[i]=-1,c[i]=1,L[i]=R[i]=-1;
	}
	mset(dp,-1);
	ll res=add(f(0,0,1),f(0,1,0));
	cout<<res<<"\n";
}
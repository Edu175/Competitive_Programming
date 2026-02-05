#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=b-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("Ofast") // may lead to precision errors
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MOD=1e9+7;

int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
#define addig(a,b) a=add(a,b)
const ll MAXN=5005,inv=fpow(4,MOD-2);
int dp[MAXN][MAXN][2][2];
int ans[MAXN][MAXN];
int main(){FIN;
	assert(mul(4,inv)==1);
	vv pot(4*MAXN+10,1);
	fore(i,1,SZ(pot))pot[i]=mul(pot[i-1],inv);
	mset(dp,0);
	fore(ta,0,2){
		auto &cur=dp[0][0][0][ta];
		cur=4;
		if(!ta)cur=mul(cur,3);
	}
	fore(i,0,MAXN-1)fore(j,0,MAXN-1)fore(ve,0,2)fore(t,0,2){
		auto &now=dp[i][j][ve][t];
		ll vio=4+2*(i+j);
		ll rest=pot[vio];
		fore(t2,0,2)fore(d2,0,4){
			array<ll,2> tap={t,t2};
			if(!ve)swap(tap[0],tap[1]);
			if(d2<2)tap[d2]=1;
			ll cur=now;
			if(!t2)cur=mul(cur,3);
			if(tap[0]&&tap[1]){ // encerrado
				addig(ans[i+1][j+1],mul(cur,rest));
			}
			else if(!tap[0]){ // abajo
				addig(dp[i+1][j][0][d2==3],cur);
			}
			else { // derecha
				assert(!tap[1]);
				addig(dp[i][j+1][1][d2==2],cur);
			}
		}
	}
	fore(dim,0,2)fore(i,1,MAXN)fore(j,1,MAXN)
		ans[i][j]=add(ans[i][j],ans[i-(dim==1)][j-(dim==0)]);
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll res=ans[n][m];
		ll tot=(n+1)*(m+1);
		res=mul(res,fpow(4,tot));
		cout<<res<<"\n";
	}
	return 0;
}

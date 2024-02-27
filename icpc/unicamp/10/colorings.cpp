#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7,MAXF=1005,MAXN=16,INF=100;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

ll fc[MAXF],fci[MAXF];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=fc[i-1]*i%MOD;
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=fci[i+1]*(i+1)%MOD;
}
ll nCr(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}
ll g[MAXN][MAXN]; ll n;
void floyd(){
	fore(k,0,n)fore(i,0,n)if(g[i][k]<INF)fore(j,0,n)if(g[k][j]<INF)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}
ll can[1ll<<MAXN];
ll dp[1ll<<MAXN][18];
int main(){FIN;
	ll m,c; cin>>n>>m>>c;
	fore(i,0,n)fore(j,0,n)g[i][j]=INF;
	fore(i,0,n)g[i][i]=0;
	fore(i,0,m){
		ll u,v; cin>>u>>v;
		g[u][v]=g[v][u]=1;
	}
	factorials();
	floyd();
	/*fore(i,0,n){
		fore(j,0,n)cout<<g[i][j]<<" ";
		cout<<"\n";
	}*/
	fore(mk,0,1ll<<n){
		can[mk]=1;
		fore(i,0,n)if((mk>>i)&1)fore(j,i+1,n)if((mk>>j)&1){
			if(min(g[i][j],g[j][i])<=2)can[mk]=0;
		}
		//cout<<"can "<<mk<<"="<<can[mk]<<"\n";
	}
	
	dp[0][0]=1;
	fore(c,1,n+1)fore(mk,0,1ll<<n){
		for(ll sb=mk;sb;sb=(sb-1)&mk)if(can[sb])
			dp[mk][c]=add(dp[mk][c],dp[mk^sb][c-1]);
		//cout<<mk<<" "<<c<<": "<<dp[mk][c]<<"\n";
	}
	ll res=0;
	fore(k,0,n+1){
		//cout<<"con "<<k<<" colores hay "<<dp[(1ll<<n)-1][k]<<"\n";
		res=add(res,dp[(1ll<<n)-1][k]*nCr(c,k)%MOD);
	}
	cout<<res<<"\n";
	return 0;
}

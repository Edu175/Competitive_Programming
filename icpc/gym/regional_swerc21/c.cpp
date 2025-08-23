#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<vv> vv2;
typedef vector<vv2> vv3;
const ll MAXN=105,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll n;
ll deg[MAXN];

struct node{
	vv3 dp;
	ll flag;
	node():dp(3,vv2(n,vv(n))),flag(0){}	
};
ll neg(ll v){if(v>MOD/2)v-=MOD;return v;}
void prnt(vv2 a){
	fore(i,0,n){
		fore(j,0,n)cerr<<neg(a[i][j])<<" ";
		cerr<<"\n";
	}
	cerr<<"\n";
}
void prnt(node a){
	cerr<<"flag "<<a.flag<<"\n";
	fore(h,0,3){
		prnt(a.dp[h]);
	}
	cerr<<"\n";
}
#define see(a) cerr<<#a<<":\n";prnt(a);

vv2 simple(vv2 &a, vv2 &a1, vv2 &b, vv2 &b1, ll flag){ // l(r) = l(a)+l(b)
	 // flag = l(a1)==0 + l(b1)==0
	cout<<"simple "<<flag<<"\n";
	see(a);
	see(a1);
	see(b);
	see(b1);
	vv2 r(n,vv(n));
	fore(i,0,n)fore(j,0,n){
		ll &res=r[i][j];
		fore(k,0,n){
			ll mas=mul(a[i][k],b[k][j]);
			ll menos=mul(deg[k]-2+flag,mul(a1[i][k],b1[k][j]));
			res=add(res,mas);
			res=sub(res,menos);
			cout<<i<<" "<<j<<" "<<k<<": "<<mas<<" "<<menos<<"\n";
		}
	}
	see(r);
	return r;
}
node merge(node a, node b){
	node c;
	auto put=[&](ll i, ll j, ll w){
		c.dp[w]=simple(a.dp[i],a.dp[i-1],b.dp[j],b.dp[j-1],
		(i-1==0&&a.flag)+(j-1==0&&b.flag));
	};
	put(2,2,2);
	put(1,2,1);
	put(1,1,0);
	// cout<<"merge ";
	// see(a)
	// see(b)
	// cout<<"=\n";
	// see(c)
	
	return c;
}

void ans(vv2 a){
	ll res=0;
	fore(i,0,n)res=add(res,a[i][i]);
	cout<<res<<"\n";
	cerr<<neg(res)<<"\n";
	exit(0);
}

int main(){
	FIN;
	ll m,k; cin>>n>>m>>k;
	node b;
	fore(i,0,n)fore(j,0,n)b.dp[0][i][j]=i==j;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		b.dp[1][u][v]=b.dp[1][v][u]=1;
	}
	fore(i,0,n){
		fore(j,0,n)deg[i]+=b.dp[1][i][j];
		// cerr<<deg[i]<<" ";
	}//cerr<<"\n";
	b.flag=1;
	b.dp[2]=simple(b.dp[1],b.dp[0],b.dp[1],b.dp[0],2);
	see(b);
	// b: {0,1,2}
	if(k<=2)ans(b.dp[k]);
	k-=2;
	ll od=0;
	if(k&1)k++,od=1;
	k>>=1;
	node ret=b;
	while(k){
		if(k&1)ret=merge(ret,b);
		b=merge(b,b); k>>=1;
	}
	see(ret)
	ans(ret.dp[2-od]);
	return 0;
}
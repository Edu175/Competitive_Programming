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
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXN=1e5+5,V=64;

ii dp[MAXN][V][2];

ii solve(vv a){
	ll n=SZ(a);
	// vector<vector<vector<ii>>>dp(n+3,vector<ii>(V,vector<>{10,0}));
	fore(i,0,V)fore(j,0,2)dp[n][i][j]={10,0};
	dp[n][0][1]={0,1};
	for(ll i=n-1;i>=0;i--)fore(x,0,V)fore(did,0,2){
		auto &res=dp[i][x][did];
		res=dp[i+1][x][did];
		auto cur=dp[i+1][x^a[i]][1];
		cur.fst++;
		if(cur.fst<res.fst)swap(cur,res);
		if(cur.fst==res.fst)res.snd=add(res.snd,cur.snd);
	}
	auto res=dp[0][0][0];
	// cout<<"solve "; imp(a);
	// cout<<res.fst<<","<<res.snd<<"\n";
	return res;
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vector<vv>sp(V,vv(n+1));
	fore(k,0,V)fore(i,1,n+1)sp[k][i]=sp[k][i-1]+(a[i-1]==k);
	while(q--){
		ll l,r; cin>>l>>r; l--;
		vv c(V);
		fore(k,0,V)c[k]=sp[k][r]-sp[k][l];
		ll res=0,num=0;
		if(c[0])res=1,num=c[0];
		else {
			ll flag=0; // possible hack
			fore(i,0,V)flag|=c[i]>1,num+=c[i]*(c[i]-1)/2;
			num%=MOD;
			if(flag)res=2;
			else {
				vv b;
				// cout<<"pingo\n";
				// assert(r-l<=V);
				fore(i,l,r)b.pb(a[i]);
				auto rq=solve(b);
				res=rq.fst;
				num=rq.snd;
				if(res>=10){cout<<"-1\n";continue;}
			}
		}
		cout<<r-l-res<<" "<<num<<"\n";
	}
	return 0;
}

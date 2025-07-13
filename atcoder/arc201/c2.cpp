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
const ll MAXS=5e5+5,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll tr[MAXS][2], qidx=1,cant[MAXS];
ll agr(ll x, ll w){
	auto &res=tr[x][w];
	if(res!=-1)return res;
	return res=qidx++;
}

ll dp[MAXS],sum[MAXS];
ll Sum(ll x){
	if(x==-1)return 0;
	return sum[x];
}
ll f(ll x){
	if(x==-1)return 0;
	auto &res=dp[x];
	if(res!=-1)return res;
	
	ll l=tr[x][0],r=tr[x][1];
	ll go0=mul(f(l),f(r)); // this calcs sum l,r
	
	sum[x]=cant[x]+Sum(l)+Sum(r);
	
	ll c=cant[x],z=sum[x]-c;
	ll go1=sub(fpow(2,c),1);
	go1=mul(go1,fpow(2,z));
	// cout<<x<<": "<<l<<","<<r<<": "<<sum[x]<<": "<<go0<<" "<<go1<<": "<<res<<"\n";
	return res=add(go0,go1);
}
void add_string(string s){
	ll x=0;
	for(auto j:s)dp[x]=-1,x=agr(x,j=='B');
	dp[x]=-1;
	cant[x]++;
}
int main(){FIN;
	mset(tr,-1);
	mset(dp,-1);
	ll n; cin>>n;
	fore(i,0,n){
		string s; cin>>s;
		add_string(s);
		// cout<<"term "<<x<<"\n";
		cout<<f(0)<<"\n";
	}
	return 0;
}

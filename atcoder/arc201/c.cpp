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

ll prod[MAXS],sum[MAXS],ans[MAXS];

vv g[MAXS];
void recalc(ll x0){
	
}

ll f(ll x){
	if(x==-1)return 0;
	auto &res=dp[x];
	if(res!=-1)return res;
	ll c=cant[x];
	ll z=sum[x]-c;
	ll go1=sub(fpow(2,c),1);
	go1=mul(go1,fpow(2,z));
	ll l=tr[x][0],r=tr[x][1];
	return res=add(go1,mul(f(l),f(r)));
}

int main(){FIN;
	mset(tr,-1);
	mset(dp,-1);
	ll n; cin>>n;
	fore(i,0,n){
		string s; cin>>s;
		ll x=0;
		for(auto j:s)x=add(x,j=='B');
		cant[x]++;
	}
	auto Cant=[&](ll x)->ll{
		if(x==-1)return 0;
		return cant[x];
	};
	for(ll x=qidx-1;x>=0;x--){
		ll l=tr[x][0],r=tr[x][1];
		sum[x]=Cant(x)+Cant(l)+Cant(r);
	}
	cout<<f(0)<<"\n";
	return 0;
}

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
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// const ll MAXV=6000,GAP=2*185;
const ll MAXV=2e7+7,GAP=2*185,MEM=1000;
const LL INF=1e17;
bitset<MAXV>cr;
void init_sieve(){
	fore(i,2,MAXV)if(!cr[i])for(LL j=1ll*i*i;j<MAXV;j+=i)cr[j]=1;
}
ll bef(ll x){
	for(ll i=x-1;i>=0;i--)if(!cr[i])return i;
	return -1;
}
ll nxt(ll x){
	fore(i,x+1,MAXV)if(!cr[i])return i;
	return -1;
}
ll bef(ll x, ll k){
	if(x<=1||k==0)return x;
	return bef(bef(x),k-1);
}
LL dp[MEM][MEM];

// vector<vv> dp;

ll n,m,p,q;
LL l,l2;
LL f(ll x, ll y){
	if(x>n||y>m||gcd(x,y)>1)return -INF;
	auto &res=dp[x-p][y-q];
	if(res!=-1)return res;
	return res=max({0LL,l+f(x+1,y),l2+f(x,y+1)});
}
LL get(ll p, ll q){
	return f(p,q)+l*p+l2*q;
}
const ll ATR=5,START=200;
int main(){FIN;
	init_sieve();
	ll t; cin>>t;
	while(t--){
		// mset(dp,-1);
		cin>>n>>m>>l>>l2;
		// if(n>m)swap(n,m),swap(l,l2); // xd
		if(n<START)p=1;
		else p=bef(n+1,ATR);
		if(m<START)q=1;
		else q=bef(m+1,ATR);
		assert(n-p+5<MEM&&m-q+5<MEM);
		fore(i,0,n-p+5)fore(j,0,m-q+5)dp[i][j]=-1;
		auto res=get(p,q);
		if(q>n); // tamo bien
		else {
			// assert(p==q);
			res=max(res,get(nxt(q),q));
			if(p==q)res=max(res,get(p,nxt(p)));
		}
		cout<<res<<"\n";
	}
	return 0;
}

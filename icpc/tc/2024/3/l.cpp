#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXV=3e5+5,MAXN=MAXV;

vector<ll>ps[MAXV];
void init_sieve(){
	fore(i,2,MAXV)if(!SZ(ps[i]))
		for(ll j=i;j<MAXV;j+=i)ps[j].pb(i);
}

ll n;
ll a[MAXN];
ll oc[MAXV];

ll mem[MAXV];
ll get(ll x){
	auto &res=mem[x];
	if(res!=-1)return res;
	ll c=0;
	ll m=SZ(ps[x]);
	fore(mk,0,1ll<<m){
		ll v=1;
		fore(j,0,m)if(mk>>j&1)v*=ps[x][j];
		if(__builtin_popcount(mk)&1)c-=oc[v];
		else c+=oc[v];
	}
	res=(c>0);
	// cout<<"get "<<x<<"? "<<c<<": "<<res<<"\n";
	return res;
}

ll dp[MAXV];
ll f(ll x){
	// cout<<"f "<<x<<"\n";
	ll &res=dp[x];
	if(res!=-1)return res;
	if(x==1)return res=0;
	ll m=res=SZ(ps[x]);
	fore(mk,0,1ll<<m){
		ll v=1;
		fore(j,0,m)if(mk>>j&1)v*=ps[x][j];
		// cout<<"pruebo "<<x<<", "<<v<<" si "<<get(v)<<"\n";
		if(!get(v))continue;
		res=min(res,1+f(x/v));
	}
	// cout<<"f "<<x<<": "<<res<<"\n";
	return res;
}

int main(){
	JET
	init_sieve();
	cin>>n;
	ll g=0;
	fore(i,0,n){
		cin>>a[i];
		g=gcd(g,a[i]);
		ll v=1;
		for(auto i:ps[a[i]])v*=i;
		a[i]=v;
	}
	if(g>1){
		cout<<"-1\n";
		return 0;
	}
	fore(i,0,n){
		ll x=a[i],m=SZ(ps[x]);
		fore(mk,0,1ll<<m){
			ll v=1;
			fore(j,0,m)if(mk>>j&1)v*=ps[x][j];
			oc[v]++;
		}
	}
	// fore(i,0,10000){
	// 	if(oc[i])cout<<"oc "<<i<<": "<<oc[i]<<"\n";
	// }
	mset(dp,-1);
	mset(mem,-1);
	// fore(i,0,n)cout<<a[i]<<" ";;cout<<"\n";
	ll res=10;
	fore(i,0,n){
		res=min(res,1+f(a[i]));
	}
	cout<<res<<"\n";
	return 0;
}
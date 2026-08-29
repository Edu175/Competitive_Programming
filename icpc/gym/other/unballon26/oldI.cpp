#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e6+5;
const ll P=100019,MOD=998244353,PI=291431979;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}
ll n;
ll a[MAXN];

vv seq;
// ll to[MAXN];
ll sum[MAXN];
ll get(ll l, ll p){
	ll res=0;
	fore(i,l,n){
		res=(res+p*a[i])%MOD;
		p=p*PI%MOD;
	}
	return res;
}
void f(ll i, ll me, ll otr, ll pme, ll Potr){
	ll suf=sum[i];
	ll te=mul(Potr,fpow(PI,n-1-i));
	suf=mul(suf,te);
	assert(suf==get(i,Potr));
	// cerr<<"f "<<i<<" "<<me<<","<<otr<<" "<<pme<<","<<Potr<<": ";
	// show(seq)
	if(i&&me<add(otr,suf)){
		show(seq)
		exit(0);
	}
	unordered_set<ll> vis;
	while(1){
		ll mn=-1;
		fore(j,i,n)if(!vis.count(j)){
			if(mn==-1||a[j]<a[mn])mn=j;
		}
		if(mn==-1)break;
		vis.insert(mn);
		// vis[mn]=1;
		// lo pongo
		ll mei=(me+pme*a[mn])%MOD;
		ll otri=otr;
		seq.pb(a[mn]);
		ll p=Potr;
		fore(j,i,mn)otri=(otri+p*a[j])%MOD,p=mul(p,PI);
		f(mn+1,mei,otri, mul(pme,PI),p);
		seq.pop_back();
	}
}

int main(){FIN;
	assert(mul(P,PI)==1);
	cin>>n;
	fore(i,0,n)cin>>a[i];
	// to[n]=n,
	sum[n]=0;
	ll p=1;
	for(ll i=n-1;i>=0;i--){
		// to[i]=to[i+1];
		// if(to[i]==n||a[i]<=a[to[i]])to[i]=i;
		sum[i]=add(mul(a[i],p),sum[i+1]);
		p=mul(p,P);
	}
	f(0,0,0,p,p);
	return 0;
}

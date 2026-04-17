#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define forr(i,a,b) for(int i=(b)-1,jet=a;i>=jet;i--)
#define pb push_back
#define ALL(a) a.begin(),a.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(a) int((a).size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;


ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
ll mulmod(ll a, ll b, ll m) {
ll r=a*b-(ll)((long double)a*b/m+.5)*m;
return r<0?r+m:r;
}
ll expmod(ll b, ll e, ll m){
if(!e)return 1;
ll q=expmod(b,e/2,m);q=mulmod(q,q,m);
return e&1?mulmod(b,q,m):q;
}
bool is_prime_prob(ll n, int a){
if(n==a)return true;
ll s=0,d=n-1;
while(d%2==0)s++,d/=2;
ll x=expmod(a,d,n);
if((x==1)||(x+1==n))return true;
fore(_,0,s-1){
x=mulmod(x,x,n);
if(x==1)return false;
if(x+1==n)return true;
}
return false;
}
bool rabin(ll n){ // true iff n is prime
if(n==1)return false;
int ar[]={2,3,5,7,11,13,17,19,23};
fore(i,0,9)if(!is_prime_prob(n,ar[i]))return false;
return true;
}
ll rho(ll n){
if(!(n&1))return 2;
ll x=2,y=2,d=1;
ll c=rand()%n+1;
while(d==1){
x=(mulmod(x,x,n)+c)%n;
y=(mulmod(y,y,n)+c)%n;
y=(mulmod(y,y,n)+c)%n;
if(x>=y)d=gcd(x-y,n);
else d=gcd(y-x,n);
}
return d==n?rho(n):d;
}
void fact(ll n, map<ll,int>& f){ //O (lg n)^3
if(n==1)return;
if(rabin(n)){f[n]++;return;}
ll q=rho(n);fact(q,f);fact(n/q,f);
}

vector<ll> get(ll n){
    map<ll,int> f;
    fact(n,f);
    vector<ll> res;
    for(auto x:f) res.pb(x.fst);
    return res;
}
ll k;
void sosdp(vv &a){
	fore(j,0,k)fore(mk,0,1ll<<k){
		if((mk>>j&1))a[mk]+=a[mk^(1<<j)];
	}
}
void revsosdp(vv &a){
	forr(j,0,k)forr(mk,0,1ll<<k){
		if((mk>>j&1))a[mk]-=a[mk^(1<<j)];
	}
}

vv multiply(vv a, vv b){
	sosdp(a); sosdp(b);
	fore(i,0,SZ(a))a[i]*=b[i];
	revsosdp(a);
	return a;
}

bool can(vv a){
	vv oc(1<<k);
	for(auto i:a)oc[i]=1;
	oc=multiply(oc,multiply(oc,oc)); // oc^3
	return oc.back();
}

int main(){FIN;
    ll n,x; cin>>n>>x;
    auto p=get(x);
    k=SZ(p);

    vector<pair<ll,ll>> v(n);
    fore(i,0,n){
        ll s,x; cin>>s>>x;
        ll mk=0;
        fore(j,0,k) if(x%p[j]==0) mk|=1<<j;
        v[i]={s,mk};
    }

    sort(ALL(v));
	ll l=0,r=n+1;
	while(r-l>1){
		ll m=(l+r)/2;
		vv b;
		fore(i,0,m)b.pb(v[i].snd);
		if(can(b))r=m;
		else l=m;
	}
	ll res=-1;
	if(l<n){
		res=max(v[l].fst,v[2].fst); // uso al menos 3
	}
	cout<<res<<"\n";
}

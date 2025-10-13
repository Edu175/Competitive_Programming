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
#pragma GCC optimize("Ofast") // may lead to precision errors
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
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
// ll rho(ll n){
// 	if(!(n&1))return 2;
// 	ll x=2,y=2,d=1;
// 	ll c=rand()%n+1;
// 	while(d==1){
// 		x=(mulmod(x,x,n)+c)%n;
// 		y=(mulmod(y,y,n)+c)%n;
// 		y=(mulmod(y,y,n)+c)%n;
// 		if(x>=y)d=gcd(x-y,n);
// 		else d=gcd(y-x,n);
// 	}
// 	return d==n?rho(n):d;
// }
// void fact(ll n, map<ll,int>& f){ //O (lg n)^3
// 	if(n==1)return;
// 	if(rabin(n)){f[n]++;return;}
// 	ll q=rho(n);fact(q,f);fact(n/q,f);
// }
// optimized version: replace rho and fact with the following:
const int MAXP=2e7+1; // sieve size
int sv[MAXP]; // sieve
ll add(ll a, ll b, ll m){return (a+=b)<m?a:a-m;}
ll rho(ll n){
	static ll s[MAXP];
	while(1){
		ll x=rand()%n,y=x,c=rand()%n;
		ll *px=s,*py=s,v=0,p=1;
		while(1){
			*py++=y=add(mulmod(y,y,n),c,n);
			*py++=y=add(mulmod(y,y,n),c,n);
			if((x=*px++)==y)break;
			ll t=p;
			p=mulmod(p,abs(y-x),n);
			if(!p)return gcd(t,n);
			if(++v==26){
				if((p=gcd(p,n))>1&&p<n)return p;
				v=0;
			}
		}
		if(v&&(p=gcd(p,n))>1&&p<n)return p;
	}
}
void init_sv(){
	fore(i,2,MAXP)if(!sv[i])for(ll j=i;j<MAXP;j+=i)sv[j]=i;
}
void fact(ll n, set<ll>& f){ // call init_sv first!!!
	for(auto&& p:f){
		while(n%p==0){
			// p.snd++;
			n/=p;
		}
	}
	if(n<MAXP)while(n>1)f.insert(sv[n]),n/=sv[n];
	else if(rabin(n))f.insert(n);
	else {ll q=rho(n);fact(q,f);fact(n/q,f);}
}
// if(n<MAXP)while(n>1)f[sv[n]]++,n/=sv[n];
// 	else if(rabin(n))f[n]++;
// 	else {ll q=rho(n);fact(q,f);fact(n/q,f);}
// }

random_device rd;
mt19937 rng(rd());
const ll MAXV=1e9-5;
int main(){FIN;
	init_sv();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll m=1;
		while(1){
			ll cur=rng()%(MAXV);
			if(rabin(n*cur+1)){
				m=cur; break;
			}
		}
		ll M=n*m+1;
		set<ll> ps;
		fact(M-1,ps);
		auto prim_rt=[&](ll a){
			for(auto p:ps)if(expmod(a,(M-1)/p,M)==1)return 0;
			return 1;
		};
		ll a=-1;
		while(1){
			ll rt=rng()%(M-1)+1;
			if(prim_rt(rt)){
				a=rt;
				break;
			}
		}
		ll k=M-1; // order of a
		ll t=m;
		// cout<<M<<": "<<k<<" "<<t<<endl;
		assert(k%t==0);
		assert(k%n==0);
		assert(t==k/n);
		a=expmod(a,t,M);
		assert(expmod(a,n,M)==1);
		cout<<a<<" "<<M<<"\n";
	}
	return 0;
}

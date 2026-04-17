#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end();
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
ll mulmod(ll a, ll b, ll m){
	ll r=a*b-(ll)((long double)a*b/m+.5)*m;
	return r<0?r+m:r;
}
ll expmod (ll b, ll e, ll m){
	if(!e) return 1;
	ll q=expmod(b,e/2,m); q=mulmod(q,q,m);
	return e&1?mulmod(b,q,m):q;
}
bool is_prime(ll n, int a){
	if(n==a) return true;
	ll s=0, d=n-1;
	while(d%2==0)s++, d/=2;
	ll x=expmod(a,d,n);
	if((x==1)||(x+1==n))return true;
	fore(_,0,s-1){
		x=mulmod(x,x,n);
		if(x==1) return false;
		if(x+1==n) return true;
	}
	return false;
}
bool rabin(ll n){
	if(n==1) return false;
	int ar[]={2,3,5,7,11,13,17,19,23};
	fore(i,0,9)if(!is_prime(n,ar[i]))return false;
	return true;
}
ll rho(ll n){
	if(!(n&1)) return 2;
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
void fact(ll n, map <ll, int> &f){
	if(n==1) return ;
	if(rabin(n)) {f[n]++;return;}
	ll q=rho(n); fact(q,f); fact(n/q,f);
}
int main(){
	ll a,b; cin>>a>>b;
	b/=gcd(a,b);
	map <ll, int> f;
	fact(b,f);
	ll R=1;
	for(ii x: f){
		R*=x.fst;
	}
	if(R<2) cout<<2<<"\n";
	else cout<<R<<"\n";
	return 0; 
}
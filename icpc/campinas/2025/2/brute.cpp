#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef __int128 xl;
typedef pair<ll,ll> ii;

ll INF=1e15;
ll MAXN=1e6;
xl mcm(ll a, ll b){
	return (xl)a*b/gcd(a,b);
}
xl exp(xl a, ll b){
	xl r=1;
	while(b){
		if(b&1)r*=a;
		a*=a,b>>=1;
	}
	return r;
}
ll root(ll k, ll n){
	ll r=pow(n,1./k)-4;
	
	for(;r<0||exp(r,k)<=n;r++)if(r<0)continue;
	return r-1;
}
bool can(ll s, ll e, ll n){ // [,)
	xl num=1;
	fore(i,s,e){
		num=mcm(num,i);
		if(num>n)return 0;
	}
	return num==n;
}
int main(){
	JET
	ll _; cin>>_; while(_--){
	ll n; cin>>n;
	ll r=sqrt(n);
	while(r*r<n) r++;
	while(r*r>n) r--;
	ll b=INF;
	ll a=INF; 
	fore(i,0,2){
		if(r*(r+1)==n) a=min(a,r), b=min(b,r+1);
		r++;
	}
	
	fore(i,2,45){
		fore(j,1,MAXN){
			if(can(j,j+i,n))  a=min(a,j), b=min(b,j+i-1);
			jet=min(jet,a);
		}
	}
	if(a==INF)cout<<"NIE\n";
	else cout<<a<<" "<<b<<"\n";
	//return 0;
	}
return 0;
}
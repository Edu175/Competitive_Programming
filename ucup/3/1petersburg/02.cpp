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
typedef long double ld;
typedef pair<ld,ld> ii;
typedef vector<ld> vv;
typedef pair<ld,ld> dd;
typedef pair<dd,dd> mx;

ii dp[11];
ii mas(ii a, ii b){
	return {a.fst+b.fst,a.snd+b.snd};
}
ii por(ld x, ii a){
	return {a.fst * x, a.snd * x};
}

ld a,b;

ii f(int n){
	if(n == 1) return {1,0};
	if(n == 2) return {0,1};
	ii &r = dp[n];
	if(r.fst>=0) return r;
	r = mas(por(a, f(n-1)), por(b, f(n-2)));
	return r; 
}


int main(){FIN;
	ld x1,xn; ll n;
	cin>>a>>b>>n>>x1>>xn;
	fore(i,0,11) dp[i] = {-1,-1};
	ii aux = f(n);
	ld x2 = (xn - aux.fst*x1) / aux.snd;
	vv rta;
	rta.pb(x1);
	rta.pb(x2);
	fore(i,2,n-1){
		rta.pb(a * rta[i-1] + b * rta[i-2]);
	}
	if(n>2)rta.pb(xn);
	for(auto x:rta) cout<<fixed<<setprecision(16)<<x<<"\n";
}

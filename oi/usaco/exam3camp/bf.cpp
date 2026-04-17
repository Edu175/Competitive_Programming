//1-12 14 16 27
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ll dis(ii a, ii b){return abs(a.fst-b.fst)+abs(a.snd-b.snd);} //manhattan
ii operator*(ll k, ii a){return {a.fst*k,a.snd*k};}
ii extendedEuclid (ll a, ll b){ //a * x + b * y = gcd(a,b)
	ll x,y;
	if (b==0) return {1,0};
	auto p=extendedEuclid(b,a%b);
	x=p.snd;
	y=p.fst-(a/b)*x;
	if(a*x+b*y==-gcd(a,b)) x=-x, y=-y;
	return {x,y};
}
pair<ii,ii> diophantine(ll a, ll b, ll r) {
	//a*x+b*y=r where r is multiple of gcd(a,b);
	ll d=gcd(a,b);
	a/=d; b/=d; r/=d;
	auto p = extendedEuclid(a,b);
	p.fst*=r; p.snd*=r;
	assert(a*p.fst+b*p.snd==r);
	return {p,{-b,a}}; // solutions: p+t*ans.snd
}
string cv(ll a){return to_string(a);}
string cv(ii a){return "{"+cv(a.fst)+","+cv(a.snd)+"}";}
string cv(pair<ii,ii> a){return "{"+cv(a.fst)+","+cv(a.snd)+"}";}
const ll MAXN=200,lim=210,C=lim-5,INF=1e15;
int main(){FIN;
	ll n,A,B; cin>>n>>A>>B;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	vector<ii>p(n);
	//p[0]=p[n+1]={{0,0},{0,0}};
	p.pb({0,0});
	ll flag=1;
	ll g=gcd(A,B);
	ii d=diophantine(A,B,g).snd;
	fore(i,0,n){
		if((-a[i])%g)flag=0;
		else p[i]=diophantine(A,B,-a[i]).fst;
	}
	if(!flag){
		cout<<"-1\n";
		return 0;
	}
//	fore(i,0,n+1)cout<<cv(p[i])<<" ";;	cout<<"\n";
	ll dp[n+5][2*lim];
	mset(dp,0);
	fore(i,0,n+1)fore(j,-C,C){
		ll &res=dp[i][j+C];
		res=INF;
		ii now=p[i]+j*d;
		if(i==0){res=dis(now,{0,0});continue;}
		ii pr=p[i-1]+(-C)*d;
		fore(k,0,2*C){
			res=min(res,dis(pr,now)+dp[i-1][k]);
			pr=pr+d;
		}
//		if(abs(j)<=2)cout<<i<<" "<<j<<": "<<res<<"\n";
	}
	ll res=dp[n][C]/2;
	cout<<res<<"\n";
	return 0;
}

//lim=55 | 78: 1-18 22 24 25 27 28 31 32
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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
const ll MAXN=200,lim=25,C=lim-5,INF=1e15;
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
	auto solve=[&](ll greedy){
		fore(i,0,n){
			auto val=[&](ll k){
				__int128 x=abs(p[i].fst+d.fst*k-(greedy&&i?p[i-1].fst:0));
				__int128 y=abs(p[i].snd+d.snd*k-(greedy&&i?p[i-1].snd:0));
				return x+y;
			};
			ll l=-INF,r=INF;
			while(r-l>5){
				ll m=(l+r)/2;
				if(val(m)>val(m+1))l=m+1;
				else r=m-1;
			}
			ll t=l;
			fore(k,l-2,r+2)if(val(t)>val(k))t=k;
			p[i]=p[i]+t*d;
		}
	//	fore(i,0,n+1)cout<<cv(p[i])<<" ";;	cout<<"\n";
		ll dp[2][2*lim];
		mset(dp,0);
		fore(i,0,n+1)fore(j,-C,C){
			ll &res=dp[i&1][j+C];
			res=INF;
			ii now=p[i]+j*d;
			if(i==0){res=dis(now,{0,0});continue;}
			ii pr=p[i-1]+(-C)*d;
			fore(k,0,2*C){
				res=min(res,dis(pr,now)+dp[(i&1)^1][k]);
				pr=pr+d;
			}
	//		if(abs(j)<=2)cout<<i<<" "<<j<<": "<<res<<"\n";
		}
		return dp[n&1][C];
	};
	ll res=min(solve(0),solve(1));
	cout<<res/2<<"\n";
	return 0;
}

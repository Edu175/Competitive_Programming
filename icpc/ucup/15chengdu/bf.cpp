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
typedef long double LD;
// typedef long double ld;
typedef __float128 ld;
typedef pair<ll,ll> ii;
typedef pair<ld,ll> par;
typedef vector<ll> vv;
// COMPILA CON -Wconversion
const ll MAXN=2e5+5;

ld abs(ld a){return a<0?-a:a;}
const ld EPS=1e-10;
ll n;
ll a[MAXN],sp[MAXN];

ld getr(ld now, ld cost){
	if(abs(now-cost)<EPS)/*{assert(0);*/return 0.5;
	ld r0=(sqrtl(cost)*sqrtl(now)-now)/(cost-now);
	ld r1=(-sqrtl(cost)*sqrtl(now)-now)/(cost-now);
	// assert(now<=cost);
	assert((0<r0&&r0<1)^(0<r1&&r1<1));
	// cerr<<r0<<" "<<r1<<"\n";
	if(0<r0&&r0<1)return r0;
	return r1;
}
ld get(ld now, ld cost){
	if(cost==0)return now;
	ld r=getr(now,cost);
	return now/r+cost/(1-r);
}
const ll INF=MAXN*MAXN*1e5; // max sum*cant

// assuming all above is correct
// => something is incorrect
// wolfram qlia
const ld ANS=54810.820372148860713;
// const ld ANS=38.330302779823360;
int main(){FIN;
	ll n,k; cin>>n>>k;
	vv a(n),sp(n+1);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	vv per(n); fore(i,n-k+1,n)per[i]=1;
	ld res=INF;
	// do{
		// cout<<"new a ";; imp(per)
		do{
			auto p=per; p.insert(p.begin(),1);
			ld cost=0;
			ll sum=0;
			ll cant=0;
			fore(i,0,n){
				sum+=a[i],cant++;
				if(i==n-1||p[i+1]){
					cost=get(sum*cant,cost);
					sum=cant=0;
				}
			}
			res=min(res,cost);
			// if(abs(cost-ANS)<EPS){
			// 	cout<<"PINGA\n";
			// 	imp(p)
			// 	imp(a)
			// }
		}while(next_permutation(ALL(per)));
	// }while(next_permutation(ALL(a)));
	cout<<fixed<<setprecision(15)<<(LD)res<<"\n";
	cout<<fixed<<setprecision(15)<<(LD)sqrtl(res)<<"\n";
	return 0;
}

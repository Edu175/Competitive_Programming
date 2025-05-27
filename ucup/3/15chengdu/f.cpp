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
typedef long double ld;
// typedef __float128 ld;
typedef pair<ll,ll> ii;
typedef pair<ld,ll> par;
typedef vector<ll> vv;
// COMPILA CON -Wconversion
const ll MAXN=2e5+5;

// ld abs(ld a){return a<0?-a:a;}
const ld EPS=1e-25;
bool equal(ld a, ld b){
	return abs(a-b)<=EPS*max((ld)1,abs(b));
}
ll n;
ll a[MAXN],sp[MAXN];

ld getr(ld now, ld cost){
	if(equal(now,cost))return 0.5;
	ld r0=(sqrtf128(cost)*sqrtf128(now)-now)/(cost-now);
	ld r1=(-sqrtf128(cost)*sqrtf128(now)-now)/(cost-now);
	assert((0<r0&&r0<1)^(0<r1&&r1<1));
	if(0<r0&&r0<1)return r0;
	return r1;
}
ld get(ld now, ld cost){
	if(cost==0)return now;
	ld r=getr(now,cost);
	return now/r+cost/(1-r);
}
par dp[MAXN];
ld lam;
par cost(ll l, ll r){
	ll now=(r-l)*(sp[r]-sp[l]);
	par ret={get(now,dp[r].fst),dp[r].snd+1};
	return ret;
}

bool cmp(par a, par b){
	ld ca=a.fst+lam*a.snd;
	ld cb=b.fst+lam*b.snd;
	if(equal(ca,cb))return a.snd<b.snd;
	return ca<cb;
}

par aliens(ld _lam, ll dbg=0){
	lam=_lam;
	deque<ii>dq; dq.pb({n-1,n});
	for(ll j=n-1;j>=0;j--){ // info hasta (j
		// if(dbg){
		// 	cout<<j<<": ";
		// 	for(auto i:dq)cout<<i.fst<<","<<i.snd<<" ";
		// 	cout<<"\n";
		// }
		auto opt=dq.back().snd;
		assert(dq.back().fst==j);
		dp[j]=cost(j,opt);
		if(!j)break;
		dq.pop_back();
		if(!SZ(dq)||dq.back().fst<j-1)dq.pb({j-1,opt});
		ll s=0;
		while(SZ(dq)){
			auto [i,opt]=dq.front();
			if(cmp(cost(i,j),cost(i,opt)))s=i,dq.pop_front();
			else break;
		}
		if(!SZ(dq)){assert(s==j-1);dq.pb({s,j});continue;}
		
		// if(dbg){
		// 	cout<<"after sacado prefix: ";
		// 	for(auto i:dq)cout<<i.fst<<","<<i.snd<<" ";
		// 	cout<<"\n";
		// }
		
		ll l=s,r=dq.front().fst-1;
		while(l<=r){
			ll m=(l+r)/2;
			if(cmp(cost(m,j),cost(m,dq.front().snd)))l=m+1;
			else r=m-1;
		}
		if(r>=0)dq.push_front({r,j});
	}
	// if(dbg){
	// 	cout<<"aliens "<<LD(lam)<<": "<<LD(dp[0].fst)<<" "<<dp[0].snd <<"\n";
	// 	fore(i,0,n)cout<<(LD)dp[i].fst<<","<<dp[i].snd<<" ";;cout<<"\n";
	// 	cout<<"total: "<<(LD)dp[0].fst<<" "<<dp[0].snd<<"\n\n";
	// }
	return dp[0];
}
const ll INF=MAXN*MAXN*1e5; // max sum*cant
ll REP=1000; // 110

int main(){FIN;
	ll k; cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	ld l=0,r=INF;
	while(REP--){
		ld m=(l+r)/2;
		if(aliens(m).snd<=k)r=m;
		else l=m;
	}
	// cerr<<setprecision(15)<<(LD)l<<" "<<(LD)r<<"\n";
	ld lam=r;
	auto [res,cnt]=aliens(lam);
	// aliens(lam,1);
	// aliens(580.201662563471,1);
	// res-=lam*k;
	// cerr<<(LD)lam<<": "<<(LD)res<<" "<<cnt<<"\n";
	assert(n!=88||cnt==k);
	cout<<fixed<<setprecision(15)<<(LD)sqrtf128(res)<<"\n";
	return 0;
}

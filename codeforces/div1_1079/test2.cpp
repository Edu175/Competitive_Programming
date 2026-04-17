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
#define debug(v) {cerr<<#v<<": "; for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
set<ll> badms={1,2,4,6,12};

#include "dynamic_bitset.hpp"
using namespace dybi;
// #include <tr2/dynamic_bitset>
// using namespace tr2;
bool knap(vv a){ // condition check
	ll s=accumulate(ALL(a),0ll);
	
	dynamic_bitset dp(s+1); dp[0]=1;
	// debug(a)
	for(auto v:a){
		assert(v);
		dp|=dp<<v;
		if(dp[s/2])return 0;
	}
	return 1;
	// vv oc(s+1);
	// for(auto i:a)oc[i]++;
	// fore(v,1,s+1){
	// 	auto &c=oc[v];
	// 	if(!c)continue;
	// 	if(c&1){
	// 		if(2*v<=s)oc[2*v]+=c/2;
	// 		c=1;
	// 	}
	// 	else {
	// 		if(2*v<=s)oc[2*v]+=(c-2)/2;
	// 		c=2;
	// 	}
	// 	fore(_,0,c){
	// 		dp|=dp<<v;
	// 		if(dp[s/2])return 0;
	// 	}
	// }
	// return 1;
}

bool valid(vv a, ll fg){
	
	if(!knap(a)){
		assert(fg);
		// ll c=SZ(a),r=s%c,k=s/c; // kmin
		// imp(a)
		// cerr<<c<<" "<<k<<" "<<r<<" no\n";
		// assert(k<10||k==1||k%2!=r%2);
		return 0;
	}
	// graph check
	priority_queue<ii> pq;
	fore(i,0,SZ(a))if(a[i])pq.push({a[i],i});
	while(SZ(pq)){
		auto [d,i]=pq.top(); pq.pop();
		vector<ii> bag;
		fore(_,0,d){
			if(!SZ(pq))return {};
			auto [d,j]=pq.top(); pq.pop();
			if(d-1>0)bag.pb({d-1,j});
		}
		for(auto i:bag)pq.push(i);
	}
	return 1;
	assert(0);
	
}

vv constr1(ll c, ll s){ // horizontal
	ll kmin=s/c,r=s%c;
	vv a(c,kmin);
	fore(i,0,r)a[i]++;
	return a;
}
vv constr2(ll c, ll s, ll k){ // vertical
	if(c!=(s+k-1)/k)return {};
	vv a(c,k);
	ll r=s%k;
	if(r)a.back()=r;
	assert(accumulate(ALL(a),0ll)==s);
	return a;
}
ll getm(ll n){return min(n*(n-1)/2,(ll)2e5);}
ll getn(ll m){
	ll n=1;
	while(getm(n)<m)n++;
	return n;
}
#define minig(a,b) a=min(a,b)
const ll INF=1e9;
int main(){FIN;
	ll N; cin>>N;
	vv minn(getm(N)+1,INF);
	auto mark=clock();
	ll dif=0;
	fore(c,3,min(ll(2*sqrt(SZ(minn))+10),N+1))fore(s,c,getm(c)*2+1)if(s%2==0){
		ll m=s/2;
		
		if(minn[m]<INF)continue;
		ll report=0;
		if(clock()-mark>1*CLOCKS_PER_SEC){
			cerr<<"reporting "<<c<<" "<<m<<": "<<dif<<"\n";
			report=1;
			mark=clock();
		}
		if(1){
			auto a=constr1(c,s);
			ll pudo=valid(a,1);
			if(!pudo)continue;
			ll r=s%c,k=s/c; // kmin
			assert(k%2==r%2);
			// cerr<<c<<" "<<k<<" "<<r<<"\n";
			// assert(c<10||min(r,c-r)*2.5<=c);
			if(report)cerr<<"foundit\n";
			dif=max(dif,c-getn(m));
			minig(minn[m],c);
		}
		
		fore(k,max(c-3,1ll),c){
			auto a=constr2(c,s,k);
			if(!SZ(a)||k<c-3)continue;
			if(c<3||k>=c)continue;
			if(a.back()==k&&c%2==0)continue;
			// pinga if(c%2==0)continue;
			if(!valid(a,0))continue;
			if(report)cerr<<"foundit\n";
			dif=max(dif,c-getn(m));
			minig(minn[m],c);
		}
	}
	cerr<<"dif "<<dif<<"\n";
	cout<<"minn: "; imp(minn);
	
	fore(m,1,SZ(minn)){
		ll cur=minn[m];
		cerr<<m<<": "<<cur<<"\n";
		if(cur>=INF)continue;
		ll n=getn(m);
		assert(cur>=n&&cur-n<=dif+5);
		// assert(cur==n||cur==n+1||cur==n+2);
	}
	
	vv good(SZ(minn));
	
	fore(n,1,N+1){
		ll M=getm(n)+1;
		fore(m,0,M)good[m]|=minn[m]<=n;
		if(n<8)continue;
		cout<<n<<": ";
		
		cout<<"failed: ";
		fore(i,1,M)if(!good[i])cout<<i<<" ";
		cout<<", ";
		ll last=M-1;
		cout<<"last "<<last<<"\n";
	}
	return 0;
}

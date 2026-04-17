#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
set<ll> badms={1,2,4,6,12};

#include "dynamic_bitset.hpp"
using namespace dybi;
bool valid(vv a, ll fg){
	ll s=accumulate(ALL(a),0ll);
	
	// condition check
	dynamic_bitset dp(s+1); dp[0]=1;
	for(auto i:a)dp|=dp<<i;
	if(dp[s/2]){
		assert(fg);
		ll c=SZ(a),r=s%c,k=s/c; // kmin
		// imp(a)
		// cerr<<c<<" "<<k<<" "<<r<<" no\n";
		// assert(k<10||k==1||k%2!=r%2);
		return 0;
	}
	// graph check
	while(SZ(a)){
		sort(ALL(a)); reverse(ALL(a));
		// if(a.back()<0)return 0;
		while(SZ(a)&&!a.back())a.pop_back();
		if(!SZ(a))return 1;
		ll d=a[0];
		a[0]=0;
		if(d+1>SZ(a)){
			assert(!fg);
			return 0;
		}
		fore(i,1,d+1)a[i]--;
	}
	assert(0);
	
}

// vv constr1(ll c, ll s){
// 	ll k=s/c, r=s%c;
// 	vv a(c,k); if(r)a.back()=r;
// 	return a;
// }

vv constr2(ll c, ll s){
	ll kmin=s/c,r=s%c;
	vv a(c,kmin);
	fore(i,0,r)a[i]++;
	return a;
}


int main(){FIN;
	ll N; cin>>N;
	vector<vv> goods(N+1);
	fore(n,0,SZ(goods))goods[n].resize(n*(n-1)/2+1);
	
	if(0){ // vertical
		fore(k,1,N)fore(m,1,SZ(goods.back())){
			ll s=2*m;
			ll c=(s+k-1)/k;
			vv a(c,k);
			// if(k<c-3)continue;
			ll r=s%k;
			if(r)a.back()=r;
			assert(accumulate(ALL(a),0ll)==s);
			if(c<3||k>=c)continue;
			if(!r&&c%2==0)continue;
			if(!valid(a,0))continue;
			// fore(n,c,N+1)goods[n][m]=1;
			if(c<=N)goods[c][m]=1;
		}
	}
	
	if(0){ // horizontal
		fore(c,3,N+1)fore(s,c,c*(c-1)+1)if(s%2==0&&c%2){
			ll m=s/2;
			auto a=constr2(c,s);
			ll pudo=valid(a,1);
			if(!pudo)continue;
			ll r=s%c,k=s/c; // kmin
			assert(k%2==r%2);
			// cerr<<c<<" "<<k<<" "<<r<<"\n";
			// assert(c<10||min(r,c-r)*2.5<=c);
			fore(n,c,N+1)goods[n][m]=1;
		}
	}
	
	if(1){ // all regular
		fore(k,1,N)fore(m,1,SZ(goods.back())){
			ll s=2*m;
			if(m%k==0)continue;
			if(2*m%k)continue;
			ll c=s/k;
			if(k>=c)continue;
			assert(c%2);
			assert(valid(vv(c,k),0));
			// fore(n,c,N+1)goods[n][m]=1;
			if(c<=N)goods[c][m]=1;
		}
	}
	fore(n,1,N+1)fore(m,0,SZ(goods[n]))if(m<SZ(goods[n-1]))goods[n][m]|=goods[n-1][m];
	fore(n,8,N+1){
		cout<<n<<": ";
		auto &good=goods[n];
		
		ll M=SZ(good);
		
		cout<<"failed: ";
		fore(i,1,M)if(!good[i])cout<<i<<" ";
		cout<<", ";
		ll last=M-1;
		cout<<"last "<<last<<"\n";
		// ll cnt=count(ALL(good),0ll)-!good[0];
		// ll d=n/2;
		// if(n%2==0){
		// 	assert(cnt==7);
		// 	assert(!good[last]);
		// 	assert(!good[last-d]);
		// }
		// else {
		// 	assert(cnt==8);
		// 	assert(!good[last-d]);
		// 	assert(!good[last-2*d]);
		// 	assert(!good[last-3*d]);
		// }
	}
	return 0;
}

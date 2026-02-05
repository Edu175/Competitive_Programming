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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const ll MOD=1e9+7,B=672,MAXV=5005;

bool is_p(ll x){
	for(ll i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}
map<ll,ll> fact(ll x){
	map<ll,ll> r;
	for(ll i=2;i*i<=x;i++){
		while(x%i==0)x/=i,r[i]++;
	}
	if(x>1)r[x]++;
	return r;
}
typedef bitset<B> mask;
struct matrix{
	vector<mask> a;
	ll dim=0;
	matrix():a(B),dim(0){}
	bool add(mask v){ // returns 1 if it is in the subspace
		fore(j,0,B)if(v[j])v^=a[j];
		ll p=v._Find_first();
		if(p>=B)return 1;
		dim++;
		a[p]=v;
		return 0;
	}
};

int main(){FIN;
	ll cnt=0;
	vv idx(MAXV,-1);
	fore(i,2,MAXV)if(is_p(i))idx[i]=cnt++;
	// cerr<<cnt<<" primos\n";
	assert(B>=cnt);
	matrix mt;
	ll n; cin>>n;
	fore(i,0,n){
		ll x; cin>>x;
		mask v;
		for(auto [p,e]:fact(x))v[idx[p]]=e&1;
		mt.add(v);
	}
	ll z=n-mt.dim,res=1;
	fore(i,0,z)(res+=res)%=MOD;
	cout<<res<<"\n";
	return 0;
}
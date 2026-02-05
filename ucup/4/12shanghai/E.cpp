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
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("Ofast") // may lead to precision errors
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXM=5000,MOD=998244353;
static ull mix(ull x) {
	// http://xorshift.di.unimi.it/splitmix64.c
	x += 0x9e3779b97f4a7c15;
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	return x ^ (x >> 31);
}

struct Hash{
	vector<ull> sp;
	Hash(){}
	Hash(vv a){
		ll n=SZ(a);
		sp.resize(n+1);
		fore(i,1,n+1){
			ull cur=mix(mix(a[i-1]))*mix(i-1);
			sp[i]=sp[i-1]^cur;
		}
	}
	ull get(ll s, ll e){
		return sp[e]^sp[s];
	}
};

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	vector<Hash> h(n);
	fore(i,0,n){
		vv a(m);
		fore(j,0,m/4){
			char c; cin>>c;
			ll mk=c-'0';
			if(c>='A'&&c<='Z')mk=c-'A'+10;
			fore(l,0,4)a[j*4+3-l]=mk>>l&1;
		}
		h[i]=Hash(a);
		// cout<<i<<": ";
		// fore(j,0,m)cout<<a[j];
		// cout<<endl;
	}
	cerr<<"done init\n";
	auto good=[&](ll i, ll j){
		auto &a=h[i];
		auto &b=h[j];
		ll p=0,c=0;
		while(p<m&&c<=k){
			ll l=p,r=m;
			while(r-l>1){
				ll mid=(l+r)/2;
				if(a.get(p,mid+1)==b.get(p,mid+1))l=mid;
				else r=mid;
			}
			p=r;
			if(p==m)break;
			c++; p++;
		}
		return c<=k;
	};
	ll res=1;
	fore(i,1,n){
		ll c=0;
		fore(j,0,i)c+=good(i,j);
		res=res*c%MOD;
		// cout<<i<<": "<<c<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}

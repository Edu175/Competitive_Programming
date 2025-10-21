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
ll fqrt(ll x){
	ll r=sqrt(x)-3;
	for(;r<0||r*r<=x;r++)if(r<0)continue;
	return r-1;
}

bool hay(ll l, ll r){ // [,]
	ll x=fqrt(r);
	return x*x>=l;
}

int main(){FIN;
	ll MAXN=2e5+5;
	vector<ll> sp(MAXN); // ]
	fore(i,1,MAXN)sp[i]=sp[i-1]+(i-1)*(i);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n==2){
			cout<<"-1\n";
			continue;
		}
		if(n==4){
			cout<<"1 2\n3 1\n4 1\n";
			continue;
		}
		// de mas grande a mas chico
		auto low=[&](ll k){ // k is first not set
			return sp[k+1];
		};
		auto high=[&](ll k){
			return n*(k*(k+1)/2);
		};
		ll s=0;
		vv p(n+1,-1);
		for(ll k=n-1;k>=1;k--){
			fore(v,k+1,n+1){
				ll cur=s+v*k;
				if(hay(cur+low(k-1),cur+high(k-1))){
					p[k]=v;
					s=cur;
					break;
				}
			}
			assert(p[k]!=-1);
		}
		ll r=fqrt(s);
		assert(r*r==s);
		cerr<<n<<"\n";
		// fore(i,1,n+1)if(p[i]!=-1){
		// 	cout<<i<<" "<<p[i]<<"\n";
		// }
	}
	return 0;
}

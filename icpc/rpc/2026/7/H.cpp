#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}

bool inr(ll x, ll l, ll r){
	if(l>r)swap(l,r);
	return l<x&&x<r;
}

int main(){FIN;
	ll n; cin>>n;
	vv a(n),b(n);
	fore(i,0,n){
		cin>>a[i]>>b[i];
	}
	ll res=0;
	fore(i,0,n){
		ll p=1;
		fore(j,0,n)if(i!=j){
			if(inr(a[j],a[i],b[i]))p=mul(p,(MOD+1)/2);
		}
		res=add(res,p);
	}
	cout<<res<<"\n";
	return 0;
}

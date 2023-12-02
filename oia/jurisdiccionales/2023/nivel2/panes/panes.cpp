#include <vector>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
const ll MAXN=1e5+5;

ll n;
ll A[MAXN],c[MAXN];

bool messirve(ll x){
	vector<ll>a(n);
	fore(i,0,n)a[i]=A[i];
	fore(i,0,n-1){
		if(a[i]<x){
			ll q=x-a[i];
			a[i+1]-=q+c[i];
			a[i]+=q;
		}
		if(a[i]>x){
			ll q=a[i]-x;
			a[i+1]+=max((ll)0,q-c[i]);
		}
	}
	return a[n-1]>=x;
}

int panes(vector<int> &X, vector<int> &C) {
	n=SZ(X);
	fore(i,0,n)A[i]=X[i];
	fore(i,0,n-1)c[i]=C[i];
	ll l=0,r=1e10;
	while(l<=r){
		ll m=(l+r)/2;
		if(messirve(m))l=m+1;
		else r=m-1;
	}
	return r;
}

#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
#pragma GCC optimize("unroll-loops")
int MOD=998244353;

inline int mul(ll a, ll b){
	return a*b%MOD;
}
inline void addig(int &a, const int &b){a+=b; if(a>=MOD)a-=MOD;}
// inline int add(int a, const int &b){a+=b; if(a>=MOD)a-=MOD; return a;}
inline int mul2(int a, int b){
	int res=0;
	while(b){
		if(b&1)addig(res,a);
		addig(a,a); b>>=1;
	}
	return res;
}
random_device rd;
mt19937 rng(rd());

const int ITER=1e8;

int main(){FIN;
	
	int a=rng()%(MOD/2),b=rng()%MOD;
	int r=0;
	fore(_,a,a+ITER){
		// addig(r,mul2(_,b));
		addig(r,mul2(_,b));
	}
	cerr<<r<<"\n";
	return 0;
}
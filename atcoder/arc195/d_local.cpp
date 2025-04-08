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
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}
inline ll num(const vv &a){
	ll n=SZ(a);
	ll q=0;
	fore(i,0,n){
		if(i==n-1||a[i]!=a[i+1])q++;
	}
	return q-1;
}
vv a;
ll f(ll i, ll prev){
	if(i>=SZ(a)-3)return (a[i]!=a[i-1])+(a[i]!=a[i+1])+(a[i+1]!=a[i+2]);
	ll res=f(i+1,0),fij=i&&a[i]!=a[i-1];
	if(!prev){
		swap(a[i+1],a[i+2]);
		res=min(res,1+f(i+1,1));
		swap(a[i+1],a[i+2]);
	}
	return res+fij;
}
ll get(vv &_a){
	if(SZ(_a)<=3)return num(_a);
	a=_a;
	ll ret=f(0,0);
	// cout<<"get "<<a<<": "<<ret<<"\n";
	return ret;
}

int main(){FIN;
	// cout<<get({1,2,1,2})<<"\n";
	// return 0;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv dp(n); dp[n-1]=0;
		for(ll i=n-2;i>=0;i--){
			auto &res=dp[i];
			res=n+5;
			vv b={a[i]};
			fore(j,i+1,min(n,i+14)){
				b.pb(a[j]);
				res=min(res,get(b)+dp[j]);
			}
			// cerr<<i<<"\n";
		}
		cout<<dp[0]+1<<"\n";
	}
	return 0;
}

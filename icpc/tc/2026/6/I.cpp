#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
ll lgt(ll n){
	assert(n>0);
	return n==1?0:__lg(n-1)+1;
}
struct STable{
	ll n,K;
	vector<vv> st;
	ll ty;
	ll oper(ll a, ll b){
		if(ty)return max(a,b);
		return min(a,b);
	}
	STable(vv a, ll ty):n(SZ(a)),K(lgt(n)),st(K,vv(n)),ty(ty){
		fore(i,0,n)st[0][i]=a[i];
		fore(k,1,K)fore(i,0,n)if(i+(1ll<<k)<=n){
			st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
		}
	}
	ll query(ll s, ll e){
		ll k=__lg(e-s);
		return oper(st[k][s],st[k][e-(1ll<<k)]);
	}
};

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n){
		cin>>a[i];
		a[i]--;
	}
	vv hasta(n+1,n);
	vv ul(n,n);
	for(ll i=n-1;i>=0;i--){
		hasta[i]=min(hasta[i+1],ul[a[i]]);
		ul[a[i]]=i;
	}
	// show(hasta)
	// return 0;
	STable dif(hasta,0),mxs(a,1);
	ll res=0;
	fore(l,0,n){
		ll r=l+1;
		while(r<=n&&r<=dif.query(l,r)){
			ll mx=mxs.query(l,r);
			// cerr<<l<<","<<r<<": "<<mx<<"\n";
			if(mx==r-l-1)res++,r++;
			else r=l+mx+1;
		}
	}
	cout<<res<<"\n";
	return 0;
}

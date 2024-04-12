#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,boi=b;i<boi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto skdauf:v)cout<<skdauf<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e12*(1e6+5);
struct STree{
	unordered_map<ll,ll>t; ll n;
	STree(ll n):n(n){}
	void upd(ll p, ll v){
		v-=INF;
		for(p+=n,t[p]=min(t[p],v);p>1;p>>=1)t[p>>1]=min(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=min(res,t[l++]);
			if(r&1)res=min(res,t[--r]);
		}
		return res+INF;
	}
};

int main(){FIN;
	ll b,p,d,n; cin>>b>>p>>d>>n;
	vector<ll>a={0};
	fore(i,0,n){
		ll x; cin>>x; a.pb(x);
	}
	n++;
	a.pb(b);
	vector<ll>dp(n+5);
	STree st(p);
	ll res=0;
	for(ll i=n-1;i>=0;i--){
		//     x     +  q               *d
		res=b-a[i]+((b-a[i]+p-1)/p-1)*d;
		ll r0=st.query(0,a[i]%p)-(a[i]/p)*d-a[i]+a[i]%p-d;
		ll r1=st.query(a[i]%p,a[i]%p+1)-(a[i]/p)*d-a[i]+a[i]%p-d;
		ll r2=st.query(a[i]%p+1,p)-(a[i]/p)*d-a[i]+a[i]%p+p;
		//cout<<i<<": "<<res<<" "<<r0<<" "<<r1<<" "<<r2<<": ";
		res=min({res,r0,r1,r2});
		ll v=res+(a[i]/p)*d+a[i]-a[i]%p;
		//cout<<res<<": "<<a[i]%p<<","<<v<<"\n";
		//cout<<res<<"+"<<a[i]/p<<"*"<<d<<"+"<<a[i]<<"+"<<a[i]%p<<"\n";
		st.upd(a[i]%p,v);
	}
	cout<<res<<"\n";
	return 0;
}

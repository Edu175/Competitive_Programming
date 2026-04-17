#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll cu(ll n, ll p){ // cuantos hay <=n congruentes a 1 mod p 
	if(n<=0)return 0;
	n--;
	ll res=n/p+1;
	return res;
}
ll fm(ll s, ll p){ // first congr a 1 mod p > a s
	if(s<=0)return 1;
	ll r=s/p*p+1;
	while(r<=s)r+=p;
	assert(r%p==1&&r>s);
	return r;
}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll p,m; cin>>p>>m;
		ll s=max(m-p-5,-1ll);
		ll e=m+p+5;
		 // (s,e)
		ll res=cu(s,p);
		// cerr<<s<<","<<e<<"\n";
		// cerr<<res<<": ";
		for(ll x=fm(s,p);x<e;x+=p){
			// cerr<<"proba "<<x<<" | ";
			res+=(x^(p-1))<=m;
		}
		cout<<res<<"\n";
	}
	return 0;
}
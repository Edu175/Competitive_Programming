#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// const ll MAXM=1e9;
ll cost(vv a){
	ll n=SZ(a);
	assert(accumulate(ALL(a),0ll)==0);
	ll po=0;
	ll res=0;
	fore(i,0,n){
		while(a[i]<0){
			while(po<n&&a[po]<=0)po++;
			assert(po<n);
			ll q=min(a[po],-a[i]);
			a[po]-=q,a[i]+=q;
			res+=abs(po-i)*q;
		}
	}
	assert(a==vv(n,0));
	return res;
}
ll k;
ll cost(vv a, ll m){
	a[0]+=m;
	ll s=-accumulate(ALL(a),0ll);
	a.back()+=s;
	ll res=k*(abs(m)+abs(s));
	return res+cost(a);
}

int main(){FIN;
	ll n; cin>>n>>k;
	vv a(n);
	ll sum=0;
	fore(ty,0,2)fore(i,0,n){
		ll x; cin>>x;
		sum+=abs(x);
		a[i]+=(ty?-1:1)*x;
	}
	const ll MAXM=sum;
	ll l=-MAXM,r=MAXM;
	// fore(i,l,r+1)cerr<<cost(a,i)<<" ";;cerr<<" costs\n";
	while(r-l>1){
		ll m=(l+r)/2;
		if(cost(a,m)<cost(a,m+1))r=m;
		else l=m;
	}
	ll m=r;
	ll res=cost(a,m);
	cout<<res<<"\n";
	return 0;
}
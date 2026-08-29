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

int main(){FIN;
	ll n,q; cin>>n>>q;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv to(n,n);
	ll r=n-1,po=n-1; vv rs(n);
	for(ll i=n-1;i>=0;i--){
		if(i+1<n&&a[i]<a[i+1])po=r,r=i;
		while(po>r&&!(a[i]<a[po]))po--;
		to[i]=po;
		rs[i]=r;
	}
	// show(to)
	ll K=__lg(n)+1;
	vector<vv> F(K,vv(n));
	fore(x,0,n)F[0][x]=to[x];
	// F[0][n]=n;
	fore(k,1,K)fore(x,0,n)F[k][x]=F[k-1][F[k-1][x]];
	while(q--){
		ll l,r; cin>>l>>r; l--; r--; // [,]
		l=rs[l];
		if(l>=r){
			cout<<"1\n";
			continue;
		}
		ll x=l,res=1;
		for(ll k=K-1;k>=0;k--){
			ll p=F[k][x];
			if(p<r)res+=(1<<k),x=p;
		}
		// cerr<<x<<": "<<res<<": ";
		res+=a[x]<a[r];
		cout<<res<<"\n";
	}
	return 0;
}

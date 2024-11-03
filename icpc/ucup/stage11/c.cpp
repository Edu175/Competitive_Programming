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

int main(){FIN;
	ll n; cin>>n;
	vv a(n),b(n),c(n),d(n);
	vv dif;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	fore(i,0,n)cin>>c[i];
	fore(i,0,n)cin>>d[i];
	ll sumb=0;
	fore(i,0,n)dif.pb(a[i]-b[i]),sumb+=b[i];
	sort(ALL(dif));
	// sort(ALL(c));
	// sort(ALL(d));
	vector<ll> sp(n+1),sc(n+1),sd(n+1);
	fore(i,1,n+1){
		sp[i]=sp[i-1]+dif[i-1];
		sc[i]=sc[i-1]+c[i-1];
		sd[i]=sd[i-1]+d[i-1];
	}
	// cout<<sumb<<"\n";
	// imp(dif);
	// imp(sp);
	// imp(sc);
	// imp(sd);
	ll res=1e15;
	fore(k,0,n+1){
		ll resi=sumb+sp[k]+sc[k]+sd[n-k];
		res=min(res,resi);
		// cout<<k<<": "<<resi<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
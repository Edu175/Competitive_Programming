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
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll k=n+m+1;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		a.resize(unique(ALL(a))-a.begin());
		n=SZ(a);
		vv cant(k);
		for(auto v:a)for(ll i=v;i<k;i+=v)cant[i]++;
		vv hay(k);
		fore(i,0,m){
			ll x; cin>>x;
			hay[x]++;
		}
		
		ll ca=0,cb=0;
		ll both=0;
		fore(i,0,k){
			ll q=hay[i];
			if(!q)continue;
			ll c=cant[i];
			ll ta=c>0,tb=c<n;
			if(ta&&tb)both+=q;
			else {
				ca+=ta*q;
				cb+=tb*q;
			}
		}
		ca+=both&1;
		if(ca>cb)cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	return 0;
}

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
		if(m<n||m>n*(n+1)/2){
			cout<<"-1\n";
			continue;
		}
		vv a(n);
		ll sum=n,k=n;
		fore(i,1,n+1){
			sum+=i-1;
			if(m<sum){sum-=i-1;k=i-1;break;}
		}
		// cerr<<"sum "<<sum<<"\n";
		cout<<k<<"\n";
		vector<ii>ed;
		fore(i,1,k)ed.pb({i+1,i});
		m-=sum;
		// cerr<<"m "<<m<<"\n";
		fore(i,k+1,n+1){
			ll q=min(m,k-1);
			ll p=q+1;
			m-=q;
			ed.pb({p,i});
		}
		assert(!m);
		for(auto [u,v]:ed)cout<<u<<" "<<v<<"\n";
	}
	return 0;
}

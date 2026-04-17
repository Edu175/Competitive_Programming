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
typedef vector<vector<ll>> mat;


int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll cant=0;
		vector<mat> cands;
		cerr<<"solutions for n="<<n<<"\n";
		ll mit=n*(n+1)/2;
		fore(_mk,0,1ll<<mit){
			ll mk=_mk;
			mat a(n,vv(n)),b=a;
			fore(i,0,n)fore(j,0,n)if(i+j>=n-1){
				ll bo=mk&1; mk>>=1;
				b[i][j]=bo;
			}
			vv app(n);
			fore(i,0,n){
				ll sw=0;
				fore(j,0,n){
					app[j]^=b[i][j];
					sw^=app[j];
					a[i][j]^=sw^b[i][j];
				}
			}
			ll hay=0;
			fore(i,0,n)fore(j,0,n)hay|=a[i][j];
			if(hay)continue;
			ll c=__builtin_popcountll(_mk);
			if(c>cant)cands.clear(),cant=c;
			if(cant==c){
				cands.pb(b);
				cerr<<"found new "<<c<<":\n";
				for(auto r:b)imp(r)
				cout<<"\n";
			}
		}
		cerr<<"cant "<<cant<<"\n";
		// cerr<<"cands:\n";
		// for(auto a:cands){
		// 	for(auto r:a)imp(r)
		// 	cout<<"\n";
		// }
		cout<<"\n\n";
	}
	return 0;
}

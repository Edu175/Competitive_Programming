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
		ll n; cin>>n;
		vector<vv> a(n,vv(n));
		fore(i,0,n)fore(j,0,n){
			char c; cin>>c;
			a[i][j]=c-'0';
		}
		vv app(n),diag1(2*n),diag2(2*n);
		ll res=0;
		fore(i,0,n){
			fore(j,0,n){
				app[j]^=diag1[i+j]^diag2[i-j+n];
			}
			fore(j,0,n){
				a[i][j]^=app[j];
				if(a[i][j]){
					res++;
					a[i][j]^=1;
					app[j]^=1;
					diag1[i+j]^=1;
					diag2[i-j+n]^=1;
				}
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}

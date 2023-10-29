#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int mini(vector<ll>v){
	ll res=1000000001;
	for(auto i:v){
		res=min(i,res);
	}
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n;cin>>n; ll a[2*n][2*n];
		fore(i,0,2*n){
			fore(j,0,2*n){
				cin>>a[i][j];
			}
		}
		ll c=0;
		fore(i,n,2*n){
			fore(j,n,2*n)c+=a[i][j];
		}
		vector<ll>v={a[0][n],a[0][2*n-1],a[n-1][n],a[n-1][2*n-1],a[n][0],a[2*n-1][0],a[n][n-1],a[2*n-1][n-1]};
		c+=mini(v);
		cout<<c<<"\n";
	}
	 return 0;
}

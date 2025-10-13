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
	ll n,q; cin>>n>>q;
	vector<vv> b(n,vv(n)),a=b;
	fore(i,0,n)fore(j,0,n){
		char c; cin>>c;
		b[i][j]=c=='#';
	}
	fore(i,0,n-1)fore(j,0,n-1){
		a[i][j]=!b[i][j]&&!b[i+1][j]&&!b[i][j+1]&&!b[i+1][j+1];
	}
	// fore(i,0,n){
	// 	imp(a[i])
	// }
	vector<vv> sp(n+1,vv(n+1));
	fore(i,1,n+1)fore(j,1,n+1)sp[i][j]=a[i-1][j-1]+sp[i][j-1];
	fore(i,1,n+1)fore(j,1,n+1)sp[i][j]+=sp[i-1][j];
	while(q--){
		ll u,d,l,r; cin>>u>>d>>l>>r; u--,l--; d--,r--;
		// cout<<u<<" "<<d<<" "<<l<<" "<<r<<": ";
		ll c=sp[d][r]-sp[u][r]-sp[d][l]+sp[u][l];
		cout<<c<<"\n";
	}
	return 0;
}

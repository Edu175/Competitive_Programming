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
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vector<vv> ini(4,vv(n));
	fore(i,0,n)ini[0][i]=a[i]*(i+1)*(n-i);
	fore(i,0,n)ini[1][i]=a[i]*(n-i);
	fore(i,0,n)ini[2][i]=a[i]*(i+1);
	fore(i,0,n)ini[3][i]=a[i];
	
	vector<vv> sp(4,vv(n+1));
	fore(w,0,4)fore(i,1,n+1)sp[w][i]=sp[w][i-1]+ini[w][i-1];
	
	while(q--){
		ll l,r; cin>>l>>r; l--;
		ll rp=n-r;
		ll term0=sp[0][r]-sp[0][l];
		ll term1=-l*(sp[1][r]-sp[1][l]);
		ll term2=-rp*(sp[2][r]-sp[2][l]);
		ll term3=l*rp*(sp[3][r]-sp[3][l]);
		ll res=term0+term1+term2+term3;
		cout<<res<<"\n";
	}
	return 0;
}

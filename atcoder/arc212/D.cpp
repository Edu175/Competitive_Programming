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
	vector<vv> a(n,vv(n));
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	vv val(n);
	fore(i,0,n)val[i]=accumulate(ALL(a[i]),0ll);
	string ans(n,'X');
	while(1){
		ll p=-1;
		fore(i,0,n)if(val[i]<0)p=i;
		if(p==-1)break;
		ans[p]^=1;
		fore(i,0,n){
			val[i]-=2*a[i][p];
			a[i][p]*=-1;
		}
		fore(i,0,n)a[p][i]*=-1;
		val[p]*=-1;
		// cout<<accumulate(ALL(val),0ll)<<": ";
		// imp(val) cerr<<endl;
	}
	cout<<ans<<"\n";
	return 0;
}

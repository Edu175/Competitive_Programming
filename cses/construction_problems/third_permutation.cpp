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
mt19937 rng(175);

int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv b(n);
	fore(i,0,n)cin>>b[i];
	if(n==2){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	vv c(n); iota(ALL(c),1);
	while(1){
		shuffle(ALL(c),rng);
		ll fg=1;
		fore(i,0,n)fg&=(a[i]!=c[i]&&b[i]!=c[i]);
		if(fg)break;
	}
	imp(c)
	return 0;
}
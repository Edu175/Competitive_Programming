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

// even length:
// c0 > 3 c1

// else
// c0+2 > 3 c1

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	
	fore(l,0,n)fore(r,l+1,n+1){
		vv c(2);
		fore(i,l,r)c[s[i]-'0']++;
		ll fg=(r-l)%4/2;
		if((c[0]-c[1]+fg)/2>c[1]-fg){
			cout<<l+1<<" "<<r<<"\n";
		}
	}
	
	
	return 0;
}

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
ll D=400;
int main(){FIN;
	ll n; cin>>n;
	vector<vv> h(2,vv(D));
	fore(i,0,n){
		char c; cin>>c;
		ll l,r; cin>>l>>r; r++;
		fore(j,l,r)h[c=='M'][j]++;
	}
	ll res=0;
	fore(i,0,D){
		res=max(res,min(h[0][i],h[1][i]));
	}
	cout<<2*res<<"\n";
	return 0;
}
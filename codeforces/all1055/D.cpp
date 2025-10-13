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
#define ppc __builtin_popcountll

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vector<vv> sp(3,vv(n+1)); // lengths, ppc>=2, special
		fore(i,1,n+1){
			ll v=a[i-1];
			vv term={__lg(v),ppc(v)>=2,ppc(v)==2&&(v&1)};
			fore(w,0,3)sp[w][i]=sp[w][i-1]+term[w];
		}
		while(q--){
			ll l,r; cin>>l>>r; l--;
			vv c(3);
			fore(w,0,3)c[w]=sp[w][r]-sp[w][l];
			ll res=c[0]+c[1]-c[2];
			res+=c[2]/2;
			cout<<res<<"\n";
		}
	}
	return 0;
}

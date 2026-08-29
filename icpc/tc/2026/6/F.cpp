#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXD=65;

ll dp[MAXD][1<<10][2][10];
vv R; // reversed, <=
ll f(ll i, ll mk, ll z, ll b, ll fg){
	if(i==-1)return mk==0;
	ll asd=-1;
	auto &res=(fg?asd:dp[i][mk][z][b]);
	if(res!=-1)return res;
	ll e=fg?R[i]:b-1;
	res=0;
	fore(d,0,e+1){
		ll mki=mk;
		if(z||d)mki^=1<<d;
		res+=f(i-1,mki,z||(d>0),b,fg&&d==e);
	}
	return res;
}
vv tob(ll x, ll b){
	vv ret;
	while(x)ret.pb(x%b),x/=b;
	return ret;
}
ll get(vv _R, ll b){
	R=_R;
	return f(SZ(R)-1,0,0,b,1);
}
int main(){
	JET
	mset(dp,-1);
	ll q; cin>>q;
	while(q--){
		ll b,l,r; cin>>b>>l>>r;
		l--;
		auto R=tob(r,b);
		auto L=tob(l,b);
		ll res=get(R,b)-get(L,b);
		cout<<res<<"\n";
	}
	return 0;
}

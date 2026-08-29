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

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ll res=0;
	fore(b,0,n+1)fore(mk,0,1ll<<n){
		ll cur=1;
		fore(i,0,n)if(i!=b)cur=lcm(cur,((mk>>i&1)?a[i]:a[i]-1));
		cur+=b<n;
		res=max(res,cur);
	}
	cout<<res%ll(1e9+7)<<"\n";
	return 0;
}

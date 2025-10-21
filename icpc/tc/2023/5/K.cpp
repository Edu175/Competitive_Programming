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
	ll n,m; cin>>n>>m;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv sp(n+1);
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	ll res=0;
	fore(i,0,n){
		ll p=upper_bound(ALL(sp),sp[i]+m)-sp.begin();
		ll cur=p-1-i;
		res=max(res,cur);
	}
	cout<<res<<"\n";
	return 0;
}

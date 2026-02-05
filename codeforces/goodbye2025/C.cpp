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
const ll INF=1e18;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv b(n);
		b[0]=a[0];
		fore(i,1,n)b[i]=abs(a[i]);
		ll cur=accumulate(ALL(b),0ll);
		ll res=-INF;
		for(ll i=n-1;i>=0;i--){
			cur-=b[i];
			res=max(res,cur);
			cur+=-a[i];
		}
		cout<<res<<"\n";
	}
	return 0;
}

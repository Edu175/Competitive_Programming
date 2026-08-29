#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n,k; cin>>n>>k;
	vv a(n);
	fore(i,0,n){
		char c; cin>>c;
		a[i]=c=='B';
	}
	vv sp(n+1); // )
	fore(i,0,n)sp[i+1]=sp[i]+a[i];
	ll res=0,cnt=0;
	for(ll i=n;i>=0;i--){
		if(i<n)cnt+=a[i];
		if(cnt>k)break;
		ll p=lower_bound(sp.begin(),sp.begin()+i,k-cnt+1)-sp.begin()-1;
		ll cur=p+n-i;
		res=max(res,cur);
	}
	cout<<res-k<<"\n";
	return 0;
}

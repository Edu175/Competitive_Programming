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
	ll t; cin>>t;
	while(t--){
		ll n,d; cin>>n>>d;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv sp(2*n+1);
		fore(i,0,SZ(sp)-1)sp[i+1]=sp[i]+a[i%n];
		ll res=0;
		fore(i,0,n){
			ll l=i-d,r=i+d+1;
			if(l<0)l+=n,r+=n;
			ll sum=sp[r]-sp[l]-a[i];
			ll cur=2*d*a[i]-sum;
			if(cur>0)res+=cur;
		}
		cout<<res<<"\n";
	}
	return 0;
}

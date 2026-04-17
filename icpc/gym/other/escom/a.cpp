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
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ll neg=0,pos=0;
	ll ans=0;
	for(ll i=n-1;i>=0;i--){
		ll fg=a[i]>0;
		ll res=(fg?neg:pos)+a[i];
		if(fg)pos=max(pos,res);
		else neg=max(neg,res);
		ans=max(ans,res);
	}
	cout<<ans<<"\n";
	return 0;
}

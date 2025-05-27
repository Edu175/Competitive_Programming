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

bool solve(vv a){ // 1 0 -1
	// bal >= 0
	ll n=SZ(a);
	// cout<<"solve ";
	// imp(a);
	// prefijo sufijo
	vv pre(n+1),suf(n+1);
	fore(i,1,n+1)pre[i]=pre[i-1]+a[i-1];
	for(ll i=n-1;i>=0;i--)suf[i]=suf[i+1]+a[i];
	// imp(pre)
	// imp(suf)
	ll hay=0;
	for(ll i=n-2;i>0;i--){
		hay|=suf[i+1]>=0;
		if(pre[i]>=0&&hay)return 1;
	}
	// cout<<"llega a reverse\n";
	// call and reverse
	ll mx=-n-n-100;
	for(ll i=n-2;i>0;i--){
		mx=max(mx,pre[i+1]);
		if(pre[i]>=0&&mx-pre[i]>=0)return 1;
	}
	// cout<<"no hay\n";
	return 0;
	
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i],b[i]=a[i]<=k?1:-1;
		ll res=solve(b);
		reverse(ALL(b));
		res|=solve(b);
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

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
	ll c1,c2,c3,c4; cin>>c1>>c2>>c3>>c4;
	ll n,m; cin>>n>>m;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv b(m);
	fore(i,0,m)cin>>b[i];
	ll ca=0;
	fore(i,0,n)ca+=min(c1*a[i],c2);
	
	ll cb=0;
	fore(i,0,m)cb+=min(c1*b[i],c2);
	
	ca=min(ca,c3);
	cb=min(cb,c3);
	
	ll res=min(ca+cb,c4);
	cout<<res<<"\n";
	return 0;
}

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
	vv a(n),b(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,n)cin>>b[i],b[i]--;
	ll res=0,po=0;
	vv vis(n);
	fore(i,0,n){
		ll x=b[i];
		while(vis[a[po]])po++;
		if(x!=a[po])res++;
		vis[x]=1;
	}
	cout<<res<<"\n";
	return 0;
}

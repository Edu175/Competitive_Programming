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
		ll n; cin>>n;
		vector<ii> a(n);
		fore(i,0,n){
			cin>>a[i].fst>>a[i].snd;
			a[i].fst--;
			a[i].snd--;
		}
		vector<vv> hay(n);
		vv vis(n);
		fore(i,0,n){
			hay[a[i].fst].pb(a[i].snd);
			vis[a[i].snd]=1;
		}
		vv sp(n+1);
		fore(i,1,n)sp[i]=sp[i-1]+vis[i-1];
		vv R(n);
		fore(i,0,n)R[a[i].snd]++;
		ll mnl=n+5,mxl=-5;
		ll s=0,e=n-1;
		ll res=0;
		fore(t,0,n){
			ll did=0;
			for(auto y:hay[t]){
				mnl=min(mnl,y);
				mxl=max(mxl,y);
				R[y]--;
				did=1;
			}
			if(!did)continue;
			while(s<n&&!R[s])s++;
			while(e>=0&&!R[e])e--;
			ll d=max(mnl,s);
			ll u=min(mxl,e);
			// cerr<<t<<": "<<d<<" "<<u<<"\n";
			if(d>=u)continue;
			res+=max(sp[u]-sp[d],0ll);
		}
		cout<<res<<"\n";
	}
	return 0;
}

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
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		ll fij=0;
		fore(i,0,k)fij+=abs(i-k/2);
		ll res=n*n+5;
		fore(m,0,n){
			vv vis(k);
			vis[a[m]]=1;
			ll l=m-1,r=m+1,fal=k-1;
			ll resi=0;
			while(fal){
				if(l>=0&&!vis[a[l]])fal-=(vis[a[l]]=1),resi+=m-l;
				if(r<n&&!vis[a[r]])fal-=(vis[a[r]]=1),resi+=r-m;
				l--,r++;
			}
			res=min(res,resi);
			// cout<<m<<": "<<resi<<"\n";
		}
		// cout<<fij<<"\n";
		cout<<res-fij<<"\n";
	}
	return 0;
}

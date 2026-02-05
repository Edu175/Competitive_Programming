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
		ll k,n; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		auto sd=a; sort(ALL(sd));
		k--;
		ll s=sd[k];
		vv b;
		fore(i,0,n)if(a[i]<=s)b.pb(a[i]);
		a=b;
		n=SZ(a);
		ll l=0,r=n-1;
		vector<vv> pos(s+1);
		fore(i,0,n)pos[a[i]].pb(i);
		fore(c,0,s){
			auto v=pos[c];
			ll m=SZ(v);
			if(m){
				ll s=v[(m+1)/2-1],e=v[m/2];
				l=max(l,s);
				r=min(r,e);
			}
		}
		// cout<<s<<": "; imp(a)
		// cout<<l<<","<<r<<"\n";
		if(l>r){
			cout<<"NO\n";
			continue;
		}
		ll c=0;
		c+=r-l+1;
		ll bad=0;
		while(l!=0||r!=n-1){
			ll fl=l>0;
			ll fr=r<n-1;
			if(fl&&fr&&a[l-1]==a[r+1]){
				c+=2; l--; r++;
			}
			else if(fl&&a[l-1]==s)l--;
			else if(fr&&a[r+1]==s)r++;
			else {
				bad=1;
				break;
			}
		}
		// cout<<c<<" < "<<k<<"\n";
		bad|=c<k;
		if(bad)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}

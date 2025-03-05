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
		ll n; cin>>n;
		vv a(n);
		map<ll,vv> pos;
		vv vals;
		fore(i,0,n){
			cin>>a[i];
			vals.pb(a[i]);
			vals.pb(a[i]-1);
			pos[a[i]].pb(i);
		}
		sort(ALL(vals));
		ll res=1;
		ll mx=-1;
		fore(i,0,n){
			ll now=max(a[i],mx);
			if(mx!=now){
				for(auto it=upper_bound(ALL(vals),mx);it<vals.end()&&*it<=now;it++){
				// fore(j,mx+1,now+1){
					ll j=*it;
					ll p=upper_bound(ALL(pos[j]),i)-pos[j].begin();
					ll q=SZ(pos[j])-p;
					ll resi=n-i-q;
					res=max(res,resi);
					cout<<i<<" "<<j<<": "<<q<<" "<<resi<<"\n";
				}
				mx=now;
			}
		}
		
		cout<<res<<"\n";
	}
	return 0;
}

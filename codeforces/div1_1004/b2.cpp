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
		vv vals;
		map<ll,vv> pos;
		map<ll,ll>pr;
		fore(i,0,n){
			cin>>a[i]; vals.pb(a[i]);
			pos[a[i]].pb(i);
			if(!pr.count(a[i]))pr[a[i]]=i;
		}
		sort(ALL(vals)); reverse(ALL(vals));
		fore(i,1,SZ(vals)){
			pr[vals[i]]=min(pr[vals[i]],pr[vals[i-1]]);
		}
		ll res=1;
		for(mex,0,n)if(){
			ll p=upper_bound(ALL(pos[mex]),pr[mex])-pos[mex].begin();
			ll q=SZ(pos[mex])-p+1;
			res=max(res,1+q);
		}
		cout<<res<<"\n";
	}
	return 0;
}

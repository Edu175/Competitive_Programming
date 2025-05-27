#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		vv a(n*m),p(n*m);
		fore(i,0,n*m)cin>>a[i],a[i]--,p[a[i]]=i;
		ll res=n*m;
		fore(i,0,n){
			vv all;
			fore(j,i*m,i*m+m)all.pb(p[j]);
			sort(ALL(all)); reverse(ALL(all));
			ll x=all[min(k,m-1)];
			x++;
			// for(auto i:all)cout<<i<<" ";;cout<<"\n";
			// cout<<i<<": "<<x<<"\n";
			x=max(x,m);
			res=min(res,x);
		}
		cout<<res<<"\n";
	}
	return 0;
}
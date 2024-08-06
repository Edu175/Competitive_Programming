#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst;
		fore(i,0,n)cin>>a[i].snd;
		sort(ALL(a));
		ll res=0;
		fore(i,0,n){
			auto [v,c]=a[i];
			ll uc=min(m/v,c),x=uc*v;
			res=max(res,x);
			if(i<n-1&&a[i+1].fst==v+1){
				ll d=a[i+1].snd;
				ll ud=min((m-x)/(v+1),d);
				ll xi=x+ud*(v+1);
				res=max(res,xi);
				ll ex=min(c,d-ud);
				res=max(res,min(xi+ex,m));
				// if(c>=r&&d-ud>=r)res=max(res,m);
			}
		}
		// res=min(res,m);
		cout<<res<<"\n";
	}
	return 0;
}

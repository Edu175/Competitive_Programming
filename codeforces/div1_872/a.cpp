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
		ll n,m; cin>>n>>m;
		vv a(n);
		set<ll>st={0,m+1};
		ll L=0,R=0;
		fore(i,0,n){
			cin>>a[i];
			if(a[i]==-1)L++;
			else if(a[i]==-2)R++;
			else st.insert(a[i]);
		}
		vv p;
		for(auto i:st)p.pb(i);
		// sort(ALL(p));
		ll cl=0,cr=m+2-SZ(p);
		ll res=0;
		fore(i,0,SZ(p)){
			res=max(res,min(cl,L)+min(cr,R));
			if(i<SZ(p)-1){
				ll q=p[i+1]-p[i]-1;
				cl+=q;
				cr-=q;
			}
		}
		res+=SZ(p)-2;
		cout<<res<<"\n";
	}
	return 0;
}

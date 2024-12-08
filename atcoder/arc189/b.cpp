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
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv d[2];
		fore(i,0,n-1)d[i&1].pb(a[i+1]-a[i]);
		sort(ALL(d[0]));
		reverse(ALL(d[0]));
		sort(ALL(d[1]));
		reverse(ALL(d[1]));
		ll res=0,p=a[0];
		fore(i,0,n){
			res+=p;
			if(i==n-1)break;
			p+=d[i&1].back();
			d[i&1].pop_back();
		}
		cout<<res<<"\n";
	return 0;
}

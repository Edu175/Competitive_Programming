#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	vector<ii>a;
	fore(i,0,n){
		ll l,r; cin>>l>>r;
		a.pb({l,1});
		a.pb({r,-1});
	}
	sort(ALL(a));
	ll res=0,c=0;
	for(auto [i,s]:a){
		c+=s;
		res=max(res,c);
	}
	cout<<res<<"\n";
	return 0;
}

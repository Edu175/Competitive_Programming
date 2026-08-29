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
	ll n,k; cin>>n>>k;
	vector<vv> pos(k);
	vv a(n);
	fore(i,0,n){
		ll x,c; cin>>x>>c; c--;
		a[i]=x;
		pos[c].pb(i);
	}
	fore(c,0,k){
		vv ids=pos[c];
		vv vals;
		for(auto i:ids)vals.pb(a[i]);
		sort(ALL(vals));
		fore(i,0,SZ(ids))a[ids[i]]=vals[i];
	}
	auto sa=a;
	sort(ALL(sa));
	if(a==sa)cout<<"Y\n";
	else cout<<"N\n";
	return 0;
}

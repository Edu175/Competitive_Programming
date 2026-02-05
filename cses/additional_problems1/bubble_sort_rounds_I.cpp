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
	vv a(n); vector<ii> sa;
	fore(i,0,n)cin>>a[i],sa.pb({a[i],i});
	sort(ALL(sa));
	ll res=0;
	fore(i,0,n){
		ll p=sa[i].snd;
		res=max(res,p-i);
	}
	cout<<res<<"\n";
	return 0;
}
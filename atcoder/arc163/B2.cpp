#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,k; cin>>n>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	vector<ll>b;
	fore(i,2,n)b.pb(a[i]);
	sort(ALL(b));
	ll l=a[0],r=a[1];
	ll res=1e10;
	fore(i,0,SZ(b)){
		if(i+k-1>=SZ(b))break;
		ll li=b[i],ri=b[i+k-1];
		ll resi=0;
		if(li<l)resi+=l-li;
		if(ri>r)resi+=ri-r;
		res=min(res,resi);
	}
	cout<<res<<"\n";
	return 0;
}

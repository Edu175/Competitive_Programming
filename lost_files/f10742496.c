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

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	vector<ll>lis;
	fore(i,0,n){
		ll lwb=lower_bound(ALL(lis),a[i])-lis.begin();
		if(lwb==SZ(lis))lis.pb(a[i]);
		else lis[lwb]=a[i];
	}
	//imp(lis);
	cout<<SZ(lis)<<"\n";
	return 0;
}

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
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll>sp(n+1);
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	//imp(sp);
	//cout<<endl;
	ll q; cin>>q;
	while(q--){
		ll x; cin>>x; x--;
		cout<<lower_bound(ALL(sp),x+1)-sp.begin()<<" ";
	}
	cout<<"\n";
	return 0;
}
